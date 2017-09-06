#include "graphics\Context.h"
#include "graphics\RenderObject.h"
#include "graphics\Vertex.h"
#include "graphics\Draw.h"
#include "graphics\Load.h"
#include "glm\ext.hpp"
#include <ctime>

int main()
{

	Framebuffer f = { 0,800,600 };
	Framebuffer fShadow = { 0,1280,720 };

	Context context;
	context.init(800, 600);

	Vertex vquad[] = {
		{ { -1,-1,0,1 },{},{ 0,0 },{ 0,0,1,0 } },
		{ { 1,-1,0,1 },{},{ 1,0 },{ 0,0,1,0 } },
		{ { 1, 1,0,1 },{},{ 1,1 },{ 0,0,1,0 } },
		{ { -1,1,0,1 },{},{ 0,1 },{ 0,0,1,0 } }
	};
	unsigned quadidx[] = { 0,1,3, 1,2,3 };
	solveTangents(vquad, 4, quadidx, 6);
	glm::mat4 floorModel = 
		glm::rotate(glm::radians(90.f), glm::vec3(-1, 0, 0))*
		glm::scale(glm::vec3(5, 5, 1));

	Geometry quad = makeGeometry(vquad, 4, quadidx, 6);

	Geometry soulSpear = loadGeometry("../../resources/models/soulspear.obj");
	glm::mat4 ssModel;


	Geometry cube = loadGeometry("../../resources/models/cube.obj");
	glm::mat4 cube_model = glm::translate(glm::vec3(2, 1, -1));


	Texture tex = loadTexture("../../resources/textures/soulspear_diffuse.tga");
	Texture tex2 = loadTexture("../../resources/textures/face.jpg");
	Texture lava = loadTexture("../../resources/textures/lava.png");
	

	//camera
	glm::mat4 cam_view = glm::lookAt(
		glm::vec3(0, 2, 5), 
		glm::vec3(0, 1, 0), 
		glm::vec3(0, 1, 0));
	glm::mat4 cam_proj = glm::perspective(45.f, (float)f.width / f.height, 1.f, 10.f);

	//light direction
	glm::vec3 lightDir = glm::normalize(glm::vec3(.8f, -1, -1));
	glm::mat4 lightProj = glm::ortho<float>(-10, 10, -10, 10, -10, 10);
	glm::mat4 lightView = glm::lookAt(-lightDir, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

	//Shaders
	Shader s = loadShader("../../resources/shaders/standard.vert", "../../resources/shaders/standard.frag");

	Shader sShadow = loadShader("../../resources/shaders/shadow.vert", "../../resources/shaders/shadow.frag");
	Shader sDirect = loadShader("../../resources/shaders/direct.vert", "../../resources/shaders/direct.frag");

	while (context.step())
	{
		//Shadow Pass
		clearFrameBuffer(fShadow, false, true);
		setFlags(RenderFlag::DEPTH);
		float fTime = (float)context.getTime();

		int loc = 0, slot = 0;
		setUniforms(sShadow,loc, slot, lightProj, lightView, ssModel, tex2, tex, lightDir);
		s0_draw(fShadow, sShadow, soulSpear);

		loc = 0, slot = 0;
		setUniforms(sShadow, loc, slot, lightProj, lightView, cube_model, tex2, tex, lightDir);
		s0_draw(fShadow, sShadow, cube);

		loc = 0, slot = 0;
		setUniforms(sShadow, loc, slot, lightProj, lightView, floorModel, tex2, tex, lightDir);
		s0_draw(fShadow, sShadow, quad);

		//Light Pass
		clearFrameBuffer(f);
		setFlags(RenderFlag::DEPTH);
		float fTime = (float)context.getTime();

		loc = 0, slot = 0;
		setUniforms(sDirect, loc, slot, lightProj, lightView, ssModel, tex2, tex, lightDir);
		s0_draw(f, sDirect, soulSpear);

		loc = 0, slot = 0;
		setUniforms(sDirect, loc, slot, lightProj, lightView, cube_model, tex2, tex, lightDir);
		s0_draw(f, sDirect, cube);

		loc = 0, slot = 0;
		setUniforms(sDirect, loc, slot, lightProj, lightView, floorModel, tex2, tex, lightDir);
		s0_draw(f, sDirect, quad);
	}

	freeShader(s);
	freeShader(sShadow);
	freeShader(sDirect);

	freeTexture(tex);
	freeTexture(tex2);
	freeTexture(lava);

	freeGeometry(soulSpear);
	freeGeometry(cube);
	freeGeometry(quad);

	return 0;
}