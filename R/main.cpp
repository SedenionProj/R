#include "R.h"
#include <string> 

int main(void)
{
    R::win::init(1280, 720,"R");
    R::win::initGui();


    while (R::win::running)
    {
        R::win::clear();
        R::win::clearGui();

        ImGui::Text("R");

        R::win::drawGui();
        R::win::draw();
    }

    R::win::closeGui();
    R::win::close();
    return 0;
}