#include "R.h"

int main(void)
{
    //TODO :template type, FBO (PBO,TBO), mesh, model, presets, scene, camera, compute shaders, samper2D
    R::win::init();
    R::win::initGui();
    float vertices[] =
    {
            -1.0f, -1.0f, -0.0f,
             1.0f,  1.0f, -0.0f,
            -1.0f,  1.0f, -0.0f,
             1.0f, -1.0f, -0.0f
    };

    unsigned int indices[] =
    {
            0, 1, 2,
            0, 3, 1
    };
    
    Shader shaders("Basic.vert", "Basic.frag");
    VertexArray va;
    R::VertexBuffer vb(sizeof(vertices),vertices);
    R::IndexBuffer ib(sizeof(indices),indices);
    va.AddBuffer(vb, 3, 3, 0);

    float data[] = {
        0.5f,0.5f,0.0f,1.0f,
    };

    R::ShaderStorageBuffer ssbo(sizeof(data), data,5);

    bool hold = false;
    
    while (R::win::running)
    {
        

		if (glfwGetKey(R::win::window, GLFW_KEY_F11) == GLFW_PRESS) {
			if (!hold) {
                R::win::fullScreen(true);
			}
			hold = true;
		}
		else {
			hold = false;
		}

        R::win::clear();
        R::win::clearGui();

        R::renderer::draw(va,ib,shaders);

        ImGui::Text(std::to_string(1).c_str());

        R::win::drawGui();
        R::win::display();
    }

    R::win::closeGui();
    R::win::close();
    return 0;
}