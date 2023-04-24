#pragma once
#include "../libs/ImGui/imgui.h"
#include "../libs/ImGui/imgui_impl_glfw.h"
#include "../libs/ImGui/imgui_impl_opengl3.h"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace R {
	extern float dt;
	class win {
	public:
		static GLFWwindow* window;
		static bool running;
		static int w;
		static int h;
		static int init(const int& x,const int& y,const char* name);
		static void mode(const int& x = w, const int& y = h, const bool& fullScreen = false, const bool& hideCursor = false, const int& posX = 0, const int& posY = 30);
		static void clear();
		static void draw();
		static void close();
		static void initGui();
		static void clearGui();
		static void drawGui();
		static void closeGui();
	};
}