//Catherine Honegger and Christian Kamwangala
 //
#include "HeatSeek.h"

// Static data members of the class;
ID HeatSeek::_id =ID::playerMissile;
vector2d HeatSeek::_heatSize {17,4};
objectProperties HeatSeek::info{_id,_heatSize};

HeatSeek::HeatSeek(vector2d _heatPosition)
:Entity(_heatPosition, info),_heatSpeed {5}
{ 
} // Nothing else to do

const float HeatSeek::getSpeed() const
{
	return _heatSpeed;
}
