#include "window.h"

namespace R {
        GLFWwindow* win::window = nullptr;
        int win::w = 0;
        int win::h = 0;
        bool win::running = true;

        int win::posX = 0;
        int win::posY = 30;
        bool win::fullScreenMode = false;

        float dt = 0.0f;
        int screenW = 0;
        int screenH = 0;
        float lastFrame = 0.0f;
        double prevTime = 0.0;
        double timeDiff;
        float currentFrame = glfwGetTime();

        GLFWmonitor* monitor = NULL;

        void reloadWindow() {
            glfwSetWindowMonitor(win::window, monitor, win::posX, win::posY, win::w, win::h, 0);
            glViewport(0, 0, win::w, win::h);
        }

        int win::init( const char* name, const unsigned int& width, const unsigned int& height, const bool& fullscreen, const bool& resizable) {
            if (!glfwInit())
                return -1;

            const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

            screenW = mode->width;
            screenH = mode->height;

            glfwWindowHint(GLFW_RESIZABLE, resizable);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

            if (width == 0 or height == 0) {
                win::w = screenW;
                win::h = screenH;
            }
            else {
                win::w = width;
                win::h = height;
            }

            posX = (screenW - win::w) / 2;
            posY = (screenH - win::h) / 2;

            win::window = glfwCreateWindow(win::w, win::h, name, NULL, NULL);

            if (fullscreen) {
                win::fullScreen();
            }

            win::setPos();

            if (!window)
            {
                glfwTerminate();
                return -1;
            }

            glfwMakeContextCurrent(win::window);

            if (glewInit() != GLEW_OK) {
                std::cout << "error\n";
            }

            glViewport(0, 0, win::w, win::h);
        }

        void win::fullScreen(const bool& full, const int& x, const int& y) {
            win::fullScreenMode = full;
            win::w = x;
            win::h = y;
            if (win::fullScreenMode)
                monitor = glfwGetPrimaryMonitor();
            else
                monitor = NULL;
            std::cout << win::fullScreenMode << "\n";
            reloadWindow();
        }

        void win::setSize(const int& width, const int& height) {
            win::w = width;
            win::h = height;
            reloadWindow();
        }

        void win::setPos(const int& x, const int& y) {
            win::posX = x;
            win::posY = y;
            reloadWindow();
        }

        void win::hideCursor(const bool& hideCursor) {
            if (hideCursor)
                glfwSetInputMode(win::window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            else
                glfwSetInputMode(win::window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        }

        void win::clear() {
            win::running = !glfwWindowShouldClose(R::win::window);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            currentFrame = glfwGetTime();
            dt = currentFrame - lastFrame;
            timeDiff = currentFrame - prevTime;
            lastFrame = currentFrame;
        }

        void win::draw() {
            glfwSwapBuffers(win::window);
            glfwPollEvents();

        }

        void win::close() {
            glfwTerminate();
        }

        void win::initGui()
        {
            IMGUI_CHECKVERSION();
            ImGui::CreateContext();
            ImGuiIO& io = ImGui::GetIO();
            ImGui_ImplGlfw_InitForOpenGL(R::win::window, true);
            ImGui_ImplOpenGL3_Init("#version 330");
            ImGui::StyleColorsDark();
        }

        void win::clearGui()
        {
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();
            ImGui::Begin("Demo window");
        }

        void win::drawGui()
        {
            ImGui::End();
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        }

        void win::closeGui()
        {
            ImGui_ImplOpenGL3_Shutdown();
            ImGui_ImplGlfw_Shutdown();
            ImGui::DestroyContext();
        }
}