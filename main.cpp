#include "HighLevel/Game.h"
#include "XMLParser/AnimLoaderXML.h"

int main() {
    std::string imagesPath = "Resource/Images/";
    Game MainGame(1366, 768);

    MainGame.LoadLib("Resource/XML/ImageLib.xml");
    MainGame.LoadScene("Resource/XML/Scenes/TestScene.xml");
    auto Alpha = MainGame.GetObject("Bunny");

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
    MainGame.AddKeyAction(DELETE, [&MainGame]() {
        MainGame.DeleteObject("Bunny");
    });
    MainGame.AddKeyAction(INSERT, [&MainGame, &Alpha]() {
        MainGame.AddObject(Alpha);
    });

    while (MainGame.IsRunning()) {
        MainGame.Draw();
    }
    return 0;
}
