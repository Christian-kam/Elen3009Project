#include "CollisionDetection.h"

CollisionDetection::CollisionDetection(const std::shared_ptr<Entity> entity1, const std::shared_ptr<Entity> entity2)
:_entity1{entity1}
,_entity2{entity2}
{
}

CollisionDetection::~CollisionDetection()
{
	_entity1.reset();
	_entity2.reset();
}


bool CollisionDetection::isColide()
{

    auto originP = _entity1->getObjectProperties().ObjectSize.x/2;
    
    auto originL = _entity2->getObjectProperties().ObjectSize.x/2;
    
    vector2d object1boundryA{(_entity1->getPosition().x) - originP, (_entity1->getPosition().y) - originP};
    
    
    vector2d object1boundryC{(_entity1->getPosition().x) + originP, (_entity1->getPosition().y) + originP};
   
    
    vector2d object2boundryA{(_entity2->getPosition().x) - originL, (_entity2->getPosition().y) - originL};
    vector2d object2boundryB{(_entity2->getPosition().x) + originL, (_entity2->getPosition().y) - originL};
    
    vector2d object2boundryC{(_entity2->getPosition().x) + originL, (_entity2->getPosition().y) + originL};
    vector2d object2boundryD{(_entity2->getPosition().x) - originL, (_entity2->getPosition().y) + originL};
    
    
	if((object2boundryA.x >= object1boundryA.x && object2boundryA.x <= object1boundryC.x &&  object2boundryA.y >= object1boundryA.y && object2boundryA.y <= object1boundryC.y)
    || (object2boundryB.x >= object1boundryA.x && object2boundryB.x <= object1boundryC.x &&  object2boundryB.y >= object1boundryA.y && object2boundryB.y <= object1boundryC.y)
    || (object2boundryC.x >= object1boundryA.x && object2boundryC.x <= object1boundryC.x &&  object2boundryC.y >= object1boundryA.y && object2boundryC.y <= object1boundryC.y)
    || (object2boundryD.x >= object1boundryA.x && object2boundryD.x <= object1boundryC.x &&  object2boundryD.y >= object1boundryA.y && object2boundryD.y <= object1boundryC.y))
	{
		return true;
	}
	return false;
}
