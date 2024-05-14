#include "SmartAnt.h"

SmartAnt::SmartAnt(double x, double y) : NormalAnt::NormalAnt(x, y) {
	this->spriteSrc = "resources/sprites/orange.png";
}

void SmartAnt::MoveTo(Vector target) {
	Vector move = target - this->position;
	if (move.GetMagnitude() <= 3) return;
	move.ChangeLength(this->speed);
	this->LookAt(this->position + move);
	this->position += move;
}

void SmartAnt::SmartMove() {
	if (this->path.size() <= 0) return;
	Vector target = this->path[0];
	Vector dis = target - this->position;
	if (dis.GetMagnitude() <= 5) {
		this->path.erase(this->path.begin());
		return;
	}
	this->MoveTo(target);
}

void SmartAnt::RandomMove() {
	if (this->moveRandomTimer >= this->moveRandomDelay) {
		this->moveRandomDelay = Random::GetRandomNumber(this->delayMin, this->delayMax);
		this->RandomMoveVector();
		this->moveRandomTimer = 0;
	}
	this->position += this->moveVector;
	this->LookAt(this->moveVector);
}

void SmartAnt::Move() {
	if (this->path.size() <= 0) {
		this->RandomMove();
		//cout << "radom move\n";
	}
	else {
		this->SmartMove();
		//cout << "Smart move\n";
	}
	this->MoveAnimation();
}

void SmartAnt::UpdatePath(vector<vector<bool>> map, Vector pizzaPosition) {
	cout << "update path\n";

	vector<Cell*> cells = PathFinder::Find(map, this->position.GetX(), this->position.GetY(), pizzaPosition.GetX(), pizzaPosition.GetY());
	
	this->path.clear();
	
	if (cells.size() <= 0) {
		return;
	}

	for (int i = 0; i < cells.size(); i++) {
		Cell* cell = cells[i];
		Vector pos(cell->i * 100, cell->j * 100);
		this->path.push_back(pos);
	}

	this->path.push_back(pizzaPosition);

}
