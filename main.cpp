#include "HighLevel/Game.h"

int main() {
    Game MainGame(1366, 768);
    auto img = MainGame.LoadImage("Resource/Images/Animation.jpg");
    auto alpha = std::make_shared<GameObject>(img);
    alpha->SetPosition(-100, -100);
    alpha->SetSize(100, 100);
    alpha->SetSpeed(5);
    MainGame.AddObject(alpha);

    MainGame.addKeyAction(ESC, [&MainGame]() {
        MainGame.StopPlay();
    });

    MainGame.addKeyAction(ARROW_UP, [&alpha]() {
        alpha->Move(UP);
    });
    MainGame.addKeyAction(ARROW_DOWN, [&alpha]() {
        alpha->Move(DOWN);
    });
    MainGame.addKeyAction(ARROW_LEFT, [&alpha]() {
        alpha->Move(LEFT);
    });
    MainGame.addKeyAction(ARROW_RIGHT, [&alpha]() {
        alpha->Move(RIGHT);
    });

    while (MainGame.IsRunning()) {
        MainGame.Draw();
    }
    return 0;
}
