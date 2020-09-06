#include <iostream>
#include "LowLevel/Images/Image.h"
#include "LowLevel/Render/Render.h"

int main() {
    Render render;
    auto img = render.LoadImage("Images/testImg.png");
    render.DrawImage(img, 0, 0, 400, 400);
    render.render();
    return 0;
}
