//
// Created by matgod on 09.09.2020.
//

#ifndef STREAMENGINE_LIBRARYXML_H
#define STREAMENGINE_LIBRARYXML_H


#include <string>
#include <memory>
#include <map>
#include "../LowLevel/Images/Drawable.h"
#include "../LowLevel/Render/Render.h"
#include "AnimLoaderXML.h"

class LibraryXML {
private:
    std::map<std::string, std::shared_ptr<Drawable>> lib;
    std::shared_ptr<Render> render;
    std::shared_ptr<AnimLoaderXML> animLoader;
public:
    explicit LibraryXML(const std::shared_ptr<Render>& render);
    void LoadLibrary(const std::string& xmlPath);
    void ClearLibrary();
    std::shared_ptr<Drawable> GetDrawable(const std::string& key);
};


#endif //STREAMENGINE_LIBRARYXML_H
