/// Graphics\include\graphics\COntext.h

#pragma once

//Forward delcare GLFW window
class GLFWwindow;

class Context
{
private:
	GLFWwindow *handle;

public:
	bool init(size_t width = 800, size_t height = 600, const char *title = "IT WORK");

	bool step();
	bool term();

	bool getKey(int key);
	bool getMouseButton(int button);
	void getMousePosition(double &x_out, double &y_out);
	double getTime();

	//all the things
	/*int getInputMode(int mode);
	void setInputMode(int mode, int value);
	const char *getKeyName(int key, int scancode);
	void setCursorPos(double *xpos, double *ypos);
	GLFWcursor *createCursor(const GLFWimage *img, int xhot, int yhot);
	GLFWcursor *createStandardCursor(int shape);
	void destroyCursor(GLFWcursor* cursor);
	void setCursor(GLFWcursor cursor);
	GLFWkeyfun setKeyCallback(GLFWkeyfun cbfun);
	GLFWcharfun setCharCallback(GLFWcharfun cbfun);
	GLFWcharmodsfun setCharModsCallback(GLFWcharmodsfun cbfun);
	GLFWmousebuttonfun setMouseButtonCallback(GLFWmousebuttonfun cbfun);
	GLFWcursorposfun setCursorPosCallback(GLFWcursorposfun cbfun);
	GLFWcursorenterfun setCursorEnterCallback(GLFWcursorenterfun cbfun);
	GLFWscrollfun setScrollCallback(GLFWscrollfun cbfun);
	GLFWdropfun setDropCallback(GLFWdropfun cbfun);

	bool joystickPresent(int joy);
	const float *getJoystickAxes(int joy, int *count);
	const unsigned char *getJoystickButtons(int joy, int *count);*/
};