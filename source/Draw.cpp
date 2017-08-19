
#include "glincl.h"
#include "graphics\RenderObject.h"
#include "graphics\Draw.h"

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

void clearFrameBuffer(const Framebuffer & f)
{
	glBindFramebuffer(GL_FRAMEBUFFER, f.handle);
	glClear(GL_COLOR_BUFFER_BIT);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void setUniform(const Shader & shader, int location, float value)
{
	glProgramUniform1f(shader.handle, location, value);
}

void setUniform(const Shader & shader, int location, int value)
{
	glProgramUniform1i(shader.handle, location, value);
}

void setUniform(const Shader & shader, int location, double value)
{
	glProgramUniform1d(shader.handle, location, value);
}

void setUniform(const Shader & s, int location, const Texture & value, unsigned slot)
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, value.handle);

	glProgramUniform1i(s.handle, location, slot);
}

