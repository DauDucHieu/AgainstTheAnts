#include "SpeedyAnt.h"

SpeedyAnt::SpeedyAnt(double x, double y) : NormalAnt(x, y) {
	this->spriteSrc = "resources/sprites/speed.png";
	this->speed *= 3;
}
