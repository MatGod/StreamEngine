//
// Created by matgod on 09.09.2020.
//

#include "SceneLoaderXML.h"

#include <utility>

SceneLoaderXML::SceneLoaderXML(std::shared_ptr<LibraryXML> library, std::shared_ptr<Render> render) {
    lib = std::move(library);
    this->render = std::move(render);
}

std::unique_ptr<Scene> SceneLoaderXML::LoadScene(const std::string &sceneXMLPath) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(sceneXMLPath.c_str());

    auto retScene = std::make_unique<Scene>(render);

    if (result.status != pugi::status_ok) {
        std::cout << "Error while parsing XML: " << sceneXMLPath << ". Empty Scene returned.\n";
        return retScene;
    }
    if (!doc.child("scene")) {
        std::cout << "Error while parsing Animation XML: " << sceneXMLPath << ". This XML is not Scene!\n";
        return retScene;
    }
    for (pugi::xml_node node : doc.child("scene").children()) {
        if (std::string(node.name()) == "object") {
            auto gameObject = std::make_shared<GameObject>(node.child("name").text().as_string(),
                                                           lib->GetDrawable(node.child("toDraw").text().as_string()));
            gameObject->SetPosition(node.child("position").child("x").text().as_float(),
                                    node.child("position").child("y").text().as_float());
            gameObject->SetPosition(node.child("size").child("width").text().as_float(),
                                    node.child("size").child("height").text().as_float());
            gameObject->SetSpeed(node.child("speed").text().as_float());
            retScene->AddObject(gameObject);
        }
    }
    return retScene;
}
