/**
 * @class HeatSeek
 * @author Catherine Honegger and Christian Kamwangala
 * @date 03/10/2015
 * @file HeatSeek.h
 * @brief This class captures the abstraction of a heat seeking missile in the game
 */
#ifndef HEATSEEK_H
#define HEATSEEK_H

#include "DataTypes.h"
#include "Entity.h"

class HeatSeek : public Entity
{
public:
	/**
	 * @brief Default constructor.
	 * @param position contains the x and y coordinates of the position.
	 */
    HeatSeek(vector2d position);
	/**
	 * @brief Get the speed.
	 * This function returns the speed of the heat-seeking object.
	 * @return Speed.
	 */
    const float getSpeed() const;

private:
    
    static ID _id;
    static vector2d _heatSize;

    float _heatSpeed;
    static objectProperties info;
    
};

#endif