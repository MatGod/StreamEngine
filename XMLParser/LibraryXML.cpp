//
// Created by matgod on 09.09.2020.
//

#include "LibraryXML.h"

#include <utility>
#include <pugixml.hpp>
#include <iostream>

LibraryXML::LibraryXML(const std::shared_ptr<Render>& render){
    this->render = render;
    animLoader = std::make_shared<AnimLoaderXML>(render);
}

void LibraryXML::LoadLibrary(const std::string &xmlPath) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(xmlPath.c_str());
    if (result.status != pugi::status_ok) {
        std::cout << "Error while parsing XML: " << xmlPath << ".\nImage library is empty\n";
        return;
    }
    if (!doc.child("lib")) {
        std::cout << "Error while parsing Library XML: " << xmlPath << ".\n"
                                                                       "This XML is not Library!\n"
                                                                       "Image library is empty";
        return;
    }

    std::string imagePath = doc.child("lib").child("imagesPath").text().as_string();
    std::string animationsPath = doc.child("lib").child("animationsPath").text().as_string();

    for (pugi::xml_node node : doc.child("lib").children()) {
        std::string a = node.name();
        if (std::string(node.name()) == "image") {
            lib.insert(std::make_pair(node.child("name").text().as_string(),
                                      render->loadImage(imagePath + node.child("path").text().as_string())));
        } else if (std::string(node.name()) == "animation") {
            lib.insert(std::make_pair(node.child("name").text().as_string(),
                                      animLoader->LoadAnimation(
                                              animationsPath + node.child("path").text().as_string())));
        }
    }
}

void LibraryXML::ClearLibrary() {
    lib.clear();
}

std::shared_ptr<Drawable> LibraryXML::GetDrawable(const std::string& key) {
    return lib[key];
}
