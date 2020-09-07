#include <iostream>
#include "LowLevel/Images/Image.h"
#include "LowLevel/Render/Render.h"

int main() {
    Render render;
    auto img = render.LoadImage("Resource/Images/TestImg.png");
    while (1) {
        render.DrawImage(img, 0, 0, 1, 1);
        render.StartRender();
    }
    return 0;
}
