/**
 * @class ResourcesHolder
 * @author Catherine Honegger and Christian Kamwangala
 * @date 03/10/2015
 * @file ResourcesHolder.h
 * @brief This class is responsible for managing the game's resources.
 */

#ifndef RESOURCESHOLDER_H_INCLUDED
#define RESOURCESHOLDER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "DataTypes.h"
#include "SfmlDataTypes.h"
#include <string>


class failedToLoadPicture{};

class ResourcesHolder
{
public:
	/**
	 * @brief ResourcesHolder loadTexture.
	 * @details This function loads the game's textures.
	 * @param id is used to identify the object.
	 * @param filename is the name of the folder which holds the resources.
	 */
    void loadTexture(ID id, const std::string& filename);;
	
	/**
	 * @brief ResourcesHolder getTexture.
	 * @details This function returns the texture that matches the identifier.
	 * @param id is used to identify the object.
	 * @return The object's texture. 
	 */
    const Texture& getTexture(ID id) const;
private:
    std::map<ID, std::unique_ptr<Texture>> _mapTextures;
    
};
#endif 
