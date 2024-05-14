#include "NormalAnt.h"

NormalAnt::NormalAnt(double x, double y) : Ant::Ant(x, y) {
	this->delayMin = 1;
	this->delayMax = 3;
	this->moveRandomDelay = Random::GetRandomNumber(this->delayMin, this->delayMax);
	this->moveRandomTimer = 0;
	this->RandomMoveVector();
}

void NormalAnt::UpdateMoveVector() {
	double moveSpeed = this->speed + this->buffSpeed;
	double minSpeed = 0.9;
	moveSpeed = moveSpeed >= minSpeed ? moveSpeed : minSpeed;
	this->moveVector.ChangeLength(moveSpeed);
}

void NormalAnt::RandomMoveVector() {
	Vector move(
		Random::GetRandomNumber(-100, 100),
		Random::GetRandomNumber(-100, 100)
	);
	this->moveVector = move;
	this->UpdateMoveVector();
}

void NormalAnt::Move() {
	if(this->moveRandomTimer >= this->moveRandomDelay) {
		this->moveRandomDelay = Random::GetRandomNumber(this->delayMin, this->delayMax);
		this->RandomMoveVector();
		this->moveRandomTimer = 0;
	}
	this->position += this->moveVector;
	this->MoveAnimation();
	this->LookAt(this->moveVector);
}

void NormalAnt::Update() {
	this->moveRandomTimer += Constants::DELTA_TIME;
	if (this->IsOutOfMap()) {
		Vector reverse(-this->moveVector.GetX(), -this->moveVector.GetY());
		this->moveVector = reverse;
	}

	this->currentHp += this->buffHp;
	this->currentHp = this->currentHp < this->hp ? this->currentHp : hp;
}

void NormalAnt::SetBuffSpeed(double buff) {
	this->buffSpeed = buff;
	this->UpdateMoveVector();
}

