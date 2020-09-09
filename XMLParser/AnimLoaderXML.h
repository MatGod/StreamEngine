//
// Created by matgod on 09.09.2020.
//

#ifndef STREAMENGINE_ANIMLOADERXML_H
#define STREAMENGINE_ANIMLOADERXML_H

#include "pugixml.hpp"
#include "../LowLevel/Images/Animation.h"
#include "../LowLevel/Render/Render.h"

class AnimLoaderXML {
private:
    std::shared_ptr<Render> render;
    std::map<std::string, std::shared_ptr<Drawable>> lib;
public:
    explicit AnimLoaderXML(std::shared_ptr<Render> render);
    std::shared_ptr<Animation> LoadAnimation(const std::string& xmlDocPath);
    void LoadLib(const std::string& xmlDocPath);
};


#endif //STREAMENGINE_ANIMLOADERXML_H
