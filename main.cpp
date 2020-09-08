#include "HighLevel/Game.h"

int main() {
    Game MainGame(1366, 768);
    auto img = MainGame.LoadImage("Resource/Images/TestImg.png");
    auto alpha = std::make_shared<GameObject>(img);
    alpha->SetPosition(-100, -100);
    alpha->SetSize(100, 100);
    MainGame.AddObject(alpha);
    MainGame.addKeyAction(ESC, [&MainGame]() {
        MainGame.StopPlay();
    });
    while (MainGame.IsRunning()) {
        MainGame.Draw();
    }
    return 0;
}
