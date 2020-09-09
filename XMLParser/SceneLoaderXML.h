//
// Created by matgod on 09.09.2020.
//

#ifndef STREAMENGINE_SCENELOADERXML_H
#define STREAMENGINE_SCENELOADERXML_H

#include "LibraryXML.h"
#include "../HighLevel/Scene.h"

class SceneLoaderXML {
private:
    std::shared_ptr<LibraryXML> lib;
    std::shared_ptr<Render> render;

public:
    explicit SceneLoaderXML(std::shared_ptr<LibraryXML> library, std::shared_ptr<Render> render);
    std::unique_ptr<Scene> LoadScene(const std::string &sceneXMLPath);
};


#endif //STREAMENGINE_SCENELOADERXML_H
