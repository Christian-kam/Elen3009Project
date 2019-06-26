/**
 * @brief Random generator.
 * @details This is a helper header file used to generate random vector2d.
 * @return a random x and y.
 */
#ifndef RANDOMPOSITIONGEN_H
#define RANDOMPOSITIONGEN_H
#include <cstdlib> 
#include <ctime>  

vector2d randomPositionGen()
{
    float x = rand()%3000+370; // X limit
    float y = rand()%300+155; // y limit
    return {x,y};
}

#endif
