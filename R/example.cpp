#include "R.h"

int main(void)
{
    R::win::init();
    R::win::initGui();
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };
    
    Shader shaders("Basic.vert", "Basic.frag");
    VertexArray va;
    VertexBuffer vb(sizeof(vertices),vertices);
    
    va.AddBuffer(vb, 3, 3, 0);

    //IBO, UBO, VBO, EBO, SSBO, FBO (PBO,TBO)
    bool hold = false;
    
    while (R::win::running)
    {
        R::win::clear();
        R::win::clearGui();

		if (glfwGetKey(R::win::window, GLFW_KEY_F11) == GLFW_PRESS) {
			if (!hold) {
                R::win::fullScreen(true);
			}
			hold = true;
		}
		else {
			hold = false;
		}

        shaders.Bind();
        //glBindVertexArray(VAO);
        va.Bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);

        ImGui::Text("R");

        R::win::drawGui();
        R::win::draw();
    }

    R::win::closeGui();
    R::win::close();
    return 0;
}