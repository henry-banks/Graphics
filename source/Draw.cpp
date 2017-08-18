
#include "graphics\RenderObject.h"
#include "graphics\Draw.h"
#include "glincl.h"

void s0_draw(const Framebuffer & f, const Shader & s, const Geometry & g)
{
	//things to use for draw
	glBindFramebuffer(GL_FRAMEBUFFER, f.handle);
	glUseProgram(s.handle);
	glBindVertexArray(g.handle);

	//area of framebuffer being drawn to
	glViewport(0, 0, f.width, f.height);

	//DRAW THINGS
	glDrawElements(GL_TRIANGLES, g.size, GL_UNSIGNED_INT, 0);

	//unbind things (optional?)
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glUseProgram(0);
	glBindVertexArray(0);

}
