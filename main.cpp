#include "HighLevel/Game.h"

int main() {
    std::string imagesPath = "Resource/Images/";
    Game MainGame(1366, 768);

    std::vector<std::shared_ptr<Image>> animImages;
    for (int i = 1; i != 9; ++i) {
        animImages.push_back(MainGame.LoadImage(imagesPath + "Anim1/" + std::to_string(i) + ".png"));
    }
    auto Alpha = std::make_shared<GameObject>(animImages, 2);
    Alpha->SetPosition(-200, -200);
    Alpha->SetSize(115, 130);
    Alpha->SetSpeed(5);
    auto AlphaID = MainGame.AddObject(Alpha);

    MainGame.AddKeyAction(ESC, [&MainGame]() {
        MainGame.StopPlay();
    });

    MainGame.AddKeyAction(ARROW_UP, [&Alpha]() {
        Alpha->Move(UP);
    });
    MainGame.AddKeyAction(ARROW_DOWN, [&Alpha]() {
        Alpha->Move(DOWN);
    });
    MainGame.AddKeyAction(ARROW_LEFT, [&Alpha]() {
        Alpha->Move(LEFT);
    });
    MainGame.AddKeyAction(ARROW_RIGHT, [&Alpha]() {
        Alpha->Move(RIGHT);
    });
    MainGame.AddKeyAction(DELETE, [&MainGame, &AlphaID]() {
        MainGame.DeleteObject(AlphaID);
    });
    MainGame.AddKeyAction(INSERT, [&MainGame, &Alpha, &AlphaID]() {
        AlphaID = MainGame.AddObject(Alpha);
    });

    while (MainGame.IsRunning()) {
        MainGame.Draw();
    }
    return 0;
}
