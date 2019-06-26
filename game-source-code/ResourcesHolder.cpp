#include "ResourcesHolder.h"

void ResourcesHolder::loadTexture(ID id, const std::string& filename)
{
    std::unique_ptr<Texture> texture(new Texture());
    if(!texture->loadFromFile(filename))
        throw failedToLoadPicture{};
        
    texture->setSmooth(true);
    _mapTextures.insert(std::make_pair(id, std::move(texture)));
}

const Texture& ResourcesHolder::getTexture(ID id) const
{
    auto found = _mapTextures.find(id);
    return *found->second;
}
