#pragma once
#include "../libs/ImGui/imgui.h"
#include "../libs/ImGui/imgui_impl_glfw.h"
#include "../libs/ImGui/imgui_impl_opengl3.h"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace R {
	extern float dt;
	extern int screenW;
	extern int screenH;
	class win {
	public:
		static GLFWwindow* window;
		static bool running;
		static int w;
		static int h;

		static int posX;
		static int posY;
		static bool fullScreenMode;

		static int init(const char* name = "R", const unsigned int& width = 0, const unsigned int& height = 0,const bool& fullscreen = false, const bool& resizable = false);
		
		static void fullScreen(const bool& full = true, const int& width = w, const int& height = h);
		static void hideCursor(const bool& hideCursor = true);
		static void setSize(const int& width = w, const int& height = h);
		static void setPos(const int& x = posX, const int& y = posY);
		
		static void clear();
		static void draw();
		static void close();
		static void initGui();
		static void clearGui();
		static void drawGui();
		static void closeGui();
	};
}