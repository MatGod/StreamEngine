//
// Created by matgod on 09.09.2020.
//

#include "AnimLoaderXML.h"

#include <utility>

int NodeCount(pugi::xml_node_iterator &begin, pugi::xml_node_iterator &end);

AnimLoaderXML::AnimLoaderXML(std::shared_ptr<Render> render) : render(std::move(render)) {}

std::shared_ptr<Animation> AnimLoaderXML::LoadAnimation(const std::string &xmlDocPath) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(xmlDocPath.c_str());
    if (result.status != pugi::status_ok) {
        std::cout << "Error while parsing XML: " << xmlDocPath << ". Empty Animation returned.\n";
        return std::make_shared<Animation>(std::vector<std::shared_ptr<Image>>(), 0);
    }
    if (!doc.child("animation")) {
        std::cout << "Error while parsing Animation XML: " << xmlDocPath << ". This XML is not Animation!\n";
        return std::make_shared<Animation>(std::vector<std::shared_ptr<Image>>(), 0);
    }
    std::string rootPath = doc.child("animation").child("rootFolder").text().as_string();
    std::vector<std::shared_ptr<Image>> images;
    for (pugi::xml_node node : doc.child("animation").children()) {
        if (std::string(node.name()) == "image") {
            std::string a = node.text().as_string();
            images.push_back(render->loadImage(rootPath + node.text().as_string()));
        }
    }

    return std::make_shared<Animation>(images, doc.child("animation").child("playTime").text().as_int());
}

void AnimLoaderXML::LoadLib(const std::string &xmlDocPath) {

}

int NodeCount(pugi::xml_node_iterator &begin, pugi::xml_node_iterator &end) {
    int res = -1;
    for (; begin != end; ++begin, ++res);
    return res;
}
