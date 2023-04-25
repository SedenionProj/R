#include "R.h"

int main(void)
{
    R::win::init();
    R::win::initGui();
    
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

        ImGui::Text("R");

        R::win::drawGui();
        R::win::draw();
    }

    R::win::closeGui();
    R::win::close();
    return 0;
}