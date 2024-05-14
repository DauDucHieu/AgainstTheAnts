#include "SpeedyAnt.h"

SpeedyAnt::SpeedyAnt(double x, double y) : NormalAnt(x, y) {
	this->spriteSrc = "resources/sprites/speed.png";
	this->speed *= 2.5;
	this->hp /= 1.5;
	this->currentHp = this->hp;
}
