#include "window.h"

namespace R {
        GLFWwindow* win::window = nullptr;
        int win::w = 0;
        int win::h = 0;
        bool win::running = !glfwWindowShouldClose(R::win::window);

        float dt = 0.0f;
        float lastFrame = 0.0f;
        double prevTime = 0.0;
        double timeDiff;
        float currentFrame = glfwGetTime();


        int win::init(const int& x, const int& y, const char* name) {
            win::w = x;
            win::h = y;

            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

            if (!glfwInit())
                return -1;


            win::window = glfwCreateWindow(win::w, win::h, name, NULL, NULL);
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

        void win::mode(const int& x, const int& y,const bool& fullScreen, const bool& hideCursor, const int& posX, const int& posY) {
            win::w = x;
            win::h = y;
            std::cout << win::h;
            GLFWmonitor* monitor = NULL;
            if (fullScreen)
                monitor = glfwGetPrimaryMonitor();
            if (hideCursor) {
                glfwSetInputMode(win::window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            }
            else {
                glfwSetInputMode(win::window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            }
            
            glfwSetWindowMonitor(win::window, monitor, posX, posY, win::w, win::h, 0);
            
        }

        void win::clear() {
            win::running = !glfwWindowShouldClose(R::win::window);
            glClear(GL_COLOR_BUFFER_BIT);
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
            // Setup Dear ImGui context
            IMGUI_CHECKVERSION();
            ImGui::CreateContext();
            ImGuiIO& io = ImGui::GetIO();
            // Setup Platform/Renderer bindings
            ImGui_ImplGlfw_InitForOpenGL(R::win::window, true);
            ImGui_ImplOpenGL3_Init("#version 330");
            // Setup Dear ImGui style
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