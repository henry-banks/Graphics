#include "graphics\Context.h"
#include "graphics\RenderObject.h"
#include "graphics\Vertex.h"
#include "graphics\Draw.h"
#include "graphics\Load.h"
#include "glm\ext.hpp"
#include <ctime>

int main()
{
	Context context;
	context.init(800, 600);

	Texture tex = loadTexture("../../resources/textures/soulspear_diffuse.tga");
	Texture tex2 = loadTexture("../../resources/textures/face.jpg");
	Texture lava = loadTexture("../../resources/textures/lava.png");
	Geometry soulSpear = loadGeometry("../../resources/models/soulspear.obj");
	Shader s = loadShader("../../resources/shaders/standard.vert", "../../resources/shaders/standard.frag");

	Framebuffer f = { 0,800,600 };

	//camera
	glm::mat4 cam_view = glm::lookAt(
		glm::vec3(0, 3, -4),
		glm::vec3(0, 1, 0),
		glm::vec3(0, 1, 0));
	glm::mat4 cam_proj = glm::perspective(45.f, 800.f / 600.f, .01f, 100.f);

	//model
	glm::mat4 go_model;

	//light direction
	glm::vec3 lightDir = glm::normalize(glm::vec3(1, -1, 1));

	while (context.step())
	{
		clearFrameBuffer(f);
		setFlags(RenderFlag::DEPTH);
		float fTime = (float)context.getTime();

		go_model = glm::rotate(90.f, glm::vec3(0, 1, 0));

		int loc = 0, slot = 0;
		setUniforms(s, loc, slot, cam_proj, cam_view, go_model, tex2, lightDir);
		s0_draw(f, s, soulSpear);
	}


	freeShader(s);
	freeTexture(tex);
	freeTexture(tex2);
	freeTexture(lava);
	freeGeometry(soulSpear);
	//freeGeometry(quad);

	return 0;
}