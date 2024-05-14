#include "StageScreen.h"

bool StageScreen::isReset = false;

vector<Ant*> StageScreen::ants;
vector<Trap*> StageScreen::traps;

double StageScreen::winTimeLimit = 120;
double StageScreen::winTime = 0;

double StageScreen::trapRadius = 50;
Vector StageScreen::trapIconPosition(50, 550);
int StageScreen::trapIconRadius = 30;
bool StageScreen::isTraping = false;

Vector StageScreen::unableTrapPosition(100, 50);
int StageScreen::unableTrapRadius = 150;

double StageScreen::trapAbleDelay = 5;
double StageScreen::trapAbleTime = StageScreen::trapAbleDelay;
bool StageScreen::isTrapable = true;

Vector StageScreen::pizzaPosition(680, 500);
int StageScreen::pizzaSize = 150;
Ant* StageScreen::antBringPizza = nullptr;

int StageScreen::antHpDown = 1;
int StageScreen::trapHpDown = 1;

int StageScreen::normalAntRate = 60;
int StageScreen::speedyAntRate = 30;
int StageScreen::smartAntRate = 10;

int StageScreen::pondTrapRate = 60;
int StageScreen::honeyTrapRate = 30;
int StageScreen::blackHoleTrapRate = 10;
double StageScreen::randomTrapRateDelay = 5;
double StageScreen::randomTrapRateTime = 0;

Vector StageScreen::spawnPosition(115, 65);
double StageScreen::spawnAntDelay = 0;
double StageScreen::spawnAntTime = 0;

Constants::ANT_TYPE StageScreen::GetRandAntType() {
	int randNum = Random::GetRandomNumber(0, 100);
	if (randNum <= StageScreen::normalAntRate) {
		return Constants::AT_NORMAL;
	}
	if (randNum <= StageScreen::normalAntRate + StageScreen::speedyAntRate) {
		return Constants::AT_SPEEDY;
	}
	return Constants::AT_SMART;
}

Constants::TRAP_TYPE StageScreen::GetRandTrapType() {
	int randNum = Random::GetRandomNumber(0, 100);
	if (randNum <= StageScreen::pondTrapRate) {
		return Constants::TT_POND;
	}
	if (randNum <= StageScreen::pondTrapRate + StageScreen::honeyTrapRate) {
		return Constants::TT_HONEY;
	}
	return Constants::TT_BLACK_HOLE;
}

void StageScreen::RandomTrapRate() {
	StageScreen::randomTrapRateTime += Constants::DELTA_TIME;
	if (StageScreen::randomTrapRateTime < StageScreen::randomTrapRateDelay) return;
	StageScreen::randomTrapRateTime = 0;
	StageScreen::randomTrapRateDelay = Random::GetRandomNumber(1.0, 3.0);

	StageScreen::pondTrapRate = Random::GetRandomNumber(20, 70);
	StageScreen::honeyTrapRate = Random::GetRandomNumber(20, 50);
	if (StageScreen::pondTrapRate + StageScreen::honeyTrapRate > 100) {
		StageScreen::pondTrapRate /= 1.5;
		StageScreen::honeyTrapRate /= 1.5;
	}
	StageScreen::blackHoleTrapRate = 100 - StageScreen::pondTrapRate - StageScreen::honeyTrapRate;

}

void StageScreen::RenderTrapRate() {
	int barWidth = 150;
	int barHeight = 10;
	int y = StageScreen::trapIconPosition.GetY() - 10;
	int pondWidth = StageScreen::pondTrapRate * barWidth / 100;
	int honeyWidth = StageScreen::honeyTrapRate * barWidth / 100;
	int blackHoleWidth = StageScreen::blackHoleTrapRate * barWidth / 100;

	int pontX = StageScreen::trapIconPosition.GetX() + pondWidth / 2 + 50;
	int honeyX = pontX + pondWidth / 2 + honeyWidth / 2;
	int blackHoleX = honeyX + honeyWidth / 2 + blackHoleWidth / 2;
	SDL_Color pondColor = { 3, 132, 252 };
	SDL_Color honeyColor = { 252, 222, 3 };
	SDL_Color blackHoleColor = { 20, 15, 66 };
	Draw::PercentBar(
		pontX, y, pondWidth, barHeight, 1,
		1, 1,
		{ 0,0,0 }, pondColor, { 0,0,0 }
	);
	Draw::PercentBar(
		honeyX, y, honeyWidth, barHeight, 1,
		1, 1,
		{ 0,0,0 }, honeyColor, { 0,0,0 }
	);
	Draw::PercentBar(
		blackHoleX, y, blackHoleWidth, barHeight, 1,
		1, 1,
		{ 0,0,0 }, blackHoleColor, { 0,0,0 }
	);
}

void StageScreen::TrapEffectToAnt() {
	for (Trap* trap : StageScreen::traps) {
		for (Ant* ant : StageScreen::ants) {
			Vector dis = trap->GetPosition() - ant->GetPosition();
			if (dis.GetMagnitude() <= StageScreen::trapRadius) {
				trap->EffectToAnt(ant);
				cout << "effect\n";
			}
			else {
				if (!ant->IsEffected()) {
					ant->SetBuffSpeed(0);
					ant->SetBuffHp(0);
				}
			}
		}
	}

	for (Ant* ant : StageScreen::ants) {
		ant->UnEffected();
	}
}

bool StageScreen::IsInUnableTrapingRange() {
	Vector mouse(Constants::MOUSE_X, Constants::MOUSE_Y);
	Vector dis = mouse - StageScreen::unableTrapPosition;
	if (dis.GetMagnitude() <= StageScreen::unableTrapRadius + StageScreen::trapRadius) {
		return true;
	}
	return false;
}

void StageScreen::RenderBgImage() {
	Draw::FullImage("resources/sprites/stage-bg.png", { Constants::WINDOW_WIDTH / 2, Constants::WINDOW_HEIGHT / 2, Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT });
}

void StageScreen::RenderTraps() {
	for (Trap* trap : StageScreen::traps) {
		trap->Render();
	}
}

void StageScreen::RenderAnts() {
	for (Ant* ant : StageScreen::ants) {
		ant->Render();
	}
}

void StageScreen::RenderPizza() {
	SDL_Texture* pizzaTexture = Draw::GetTexture("resources/sprites/pizza.png");
	if (StageScreen::antBringPizza) {
		SDL_SetTextureAlphaMod(pizzaTexture, 200);
	}
	Draw::FullImage(
		"resources/sprites/pizza.png",
		{
			(int)StageScreen::pizzaPosition.GetX(),
			(int)StageScreen::pizzaPosition.GetY(),
			StageScreen::pizzaSize,
			StageScreen::pizzaSize
		}
	);
	SDL_SetTextureAlphaMod(pizzaTexture, 255);
}

void StageScreen::RenderUnableTrap() {
	SDL_Texture* texture = Draw::GetTexture("resources/sprites/cancel.png");
	SDL_SetTextureAlphaMod(texture, 100);
	Draw::FullImage(
		"resources/sprites/cancel.png",
		{
			(int)StageScreen::unableTrapPosition.GetX(),
			(int)StageScreen::unableTrapPosition.GetY(),
			StageScreen::unableTrapRadius * 2,
			StageScreen::unableTrapRadius * 2
		}
	);
	SDL_SetTextureAlphaMod(texture, 255);
}

void StageScreen::RenderTraping() {
	if (StageScreen::isTraping) {
		Draw::FullImage(
			"resources/sprites/traping.png",
			{
				Constants::MOUSE_X,
				Constants::MOUSE_Y,
				(int)StageScreen::trapRadius * 2,
				(int)StageScreen::trapRadius * 2
			}
		);
		Draw::FullImage(
			"resources/sprites/cancel.png",
			{
				(int)(StageScreen::trapIconPosition.GetX()),
				(int)(StageScreen::trapIconPosition.GetY()),
				(int)StageScreen::trapIconRadius * 2,
				(int)StageScreen::trapIconRadius * 2
			}
		);
	}
	else {
		Draw::FullImage(
			"resources/sprites/traping.png",
			{
				(int)(StageScreen::trapIconPosition.GetX()),
				(int)(StageScreen::trapIconPosition.GetY()),
				(int)StageScreen::trapIconRadius * 2,
				(int)StageScreen::trapIconRadius * 2
			}
		);
	}
}

void StageScreen::RenderTrapingTimeBar() {
	Draw::PercentBar(
		StageScreen::trapIconPosition.GetX() + 150,
		StageScreen::trapIconPosition.GetY() + 10,
		150, 10, 1,
		StageScreen::trapAbleTime, StageScreen::trapAbleDelay,
		{ 255, 255, 255 }, { 255, 0, 0 }, { 0,0,0 }
	);
}

void StageScreen::RenderWinTimeBar() {
	Draw::PercentBar(
		Constants::WINDOW_WIDTH / 2, 20,
		400, 5, 1,
		StageScreen::winTime, StageScreen::winTimeLimit,
		{ 255, 255, 255 },
		{ 255, 0, 0 },
		{ 0, 0, 0 }
	);
}

void StageScreen::Render() {
	StageScreen::RenderBgImage();
	StageScreen::RenderTraps();
	StageScreen::RenderAnts();
	StageScreen::RenderPizza();
	if (StageScreen::isTraping) StageScreen::RenderUnableTrap();
	StageScreen::RenderTraping();
	StageScreen::RenderTrapRate();
	StageScreen::RenderTrapingTimeBar();
	StageScreen::RenderWinTimeBar();
}

void StageScreen::DeleteDeadAnts() {
	int i = 0;
	while (i < StageScreen::ants.size()) {
		if (StageScreen::ants[i]->IsDead()) {
			if (StageScreen::ants[i] == StageScreen::antBringPizza) {
				StageScreen::antBringPizza = nullptr;
			}
			StageScreen::ants[i]->Dead();
			StageScreen::ants.erase(StageScreen::ants.begin() + i);
		}
		else {
			i++;
		}
	}
}

void StageScreen::DeleteDeadTraps() {
	int i = 0;
	while (i < StageScreen::traps.size()) {
		if (StageScreen::traps[i]->IsDead()) {
			StageScreen::traps[i]->Dead();
			StageScreen::traps.erase(StageScreen::traps.begin() + i);
		}
		else {
			i++;
		}
	}
}

void StageScreen::UpdateAnts() {
	for (Ant* ant : StageScreen::ants) {
		ant->Update();
		ant->Move();
		ant->DownHp(StageScreen::antHpDown);

		Vector dis = ant->GetPosition() - StageScreen::pizzaPosition;
		if (!StageScreen::antBringPizza && dis.GetMagnitude() < StageScreen::pizzaSize / 2) {
			StageScreen::antBringPizza = ant;
		}
	}
}

void StageScreen::UpdateTraps() {
	for (Trap* trap : StageScreen::traps) {
		trap->DownHp(StageScreen::trapHpDown);
	}
}

void StageScreen::BringPizza() {
	if (StageScreen::antBringPizza) {
		StageScreen::pizzaPosition = StageScreen::antBringPizza->GetPosition();
		Vector antNest = StageScreen::spawnPosition;
		int lostDis = StageScreen::pizzaSize / 2;
		Vector dis = antNest - StageScreen::pizzaPosition;
		if (dis.GetMagnitude() < lostDis) {
			EndScreen::text = "You lost!!!";
			GM::screenState = Constants::SS_END;
			StageScreen::isReset = false;
			//LoadingScreen::Load(Constants::SS_END);
		}
	}
}

void StageScreen::UpdateTraping() {
	StageScreen::trapAbleTime += Constants::DELTA_TIME;
	if (StageScreen::trapAbleTime >= StageScreen::trapAbleDelay) {
		StageScreen::isTrapable = true;
	}
	StageScreen::trapAbleTime = SDL_min(StageScreen::trapAbleTime, StageScreen::trapAbleDelay);
}

void StageScreen::UpdateWinTime() {
	StageScreen::winTime += Constants::DELTA_TIME;
	if (StageScreen::winTime >= StageScreen::winTimeLimit) {
		EndScreen::text = "You win!!!";
		GM::screenState = Constants::SS_END;
		StageScreen::isReset = false;
		//LoadingScreen::Load(Constants::SS_END);
	}
}

void StageScreen::Update() {
	StageScreen::DeleteDeadAnts();
	StageScreen::DeleteDeadTraps();
	StageScreen::UpdateAnts();
	StageScreen::UpdateTraps();
	StageScreen::TrapEffectToAnt();
	StageScreen::BringPizza();
	StageScreen::RandomTrapRate();
	StageScreen::SpawnAnt();
	StageScreen::UpdateTraping();
	StageScreen::UpdateWinTime();
}

void StageScreen::HandleEvent(SDL_Event e) {

	switch (e.type) {
		case SDL_MOUSEBUTTONDOWN:
			Vector mouse(e.motion.x, e.motion.y);
			Vector dis = mouse - StageScreen::trapIconPosition;
			if (StageScreen::isTrapable) {
				if (dis.GetMagnitude() <= StageScreen::trapIconRadius) {
					if (StageScreen::isTraping) {
						StageScreen::isTraping = false;
					}
					else {
						StageScreen::isTraping = true;
					}
				}
				else {
					if (StageScreen::isTraping && !StageScreen::IsInUnableTrapingRange()) {
						Constants::TRAP_TYPE type = StageScreen::GetRandTrapType();
						StageScreen::AddTrap(e.motion.x, e.motion.y, type);
						StageScreen::isTraping = false;
						StageScreen::isTrapable = false;
						StageScreen::trapAbleTime = 0;
					}
				}
			}
			break;

	}

}

void StageScreen::SpawnAnt() {
	StageScreen::spawnAntTime += Constants::DELTA_TIME;
	if (StageScreen::spawnAntTime < StageScreen::spawnAntDelay) return;
	StageScreen::spawnAntTime = 0;

	StageScreen::spawnAntDelay = Random::GetRandomNumber(1.0, 2.0);

	Ant* newAnt;
	Constants::ANT_TYPE antType = StageScreen::GetRandAntType();
	int spawnX = StageScreen::spawnPosition.GetX();
	int spawnY = StageScreen::spawnPosition.GetY();
	switch (antType) {
		case Constants::AT_NORMAL:
			newAnt = new NormalAnt(spawnX, spawnY);
			break;
		case Constants::AT_SPEEDY:
			newAnt = new SpeedyAnt(spawnX, spawnY);
			break;
		case Constants::AT_SMART:
			newAnt = new SmartAnt(spawnX, spawnY);
			break;
	}
	StageScreen::ants.push_back(newAnt);
}

void StageScreen::AddTrap(double addX, double addY, Constants::TRAP_TYPE trapType) {
	Trap* newTrap;
	switch (trapType) {
	case Constants::TT_POND:
		newTrap = new TrapPond(addX, addY, StageScreen::trapRadius);
		break;
	case Constants::TT_HONEY:
		newTrap = new TrapHoney(addX, addY, StageScreen::trapRadius);
		break;
	case Constants::TT_BLACK_HOLE:
		newTrap = new TrapBlackHole(addX, addY, StageScreen::trapRadius);
		break;
	}
	StageScreen::traps.push_back(newTrap);
}


void StageScreen::Reset() {
	StageScreen::ants.clear();
	StageScreen::traps.clear();
	StageScreen::winTime = 0;
	Vector pizzaPos(680, 500);
	StageScreen::pizzaPosition = pizzaPos;

	StageScreen::trapAbleDelay = 5;
	StageScreen::trapAbleTime = StageScreen::trapAbleDelay;
	StageScreen::isTrapable = true;

	StageScreen::antBringPizza = nullptr;

	StageScreen::isReset = true;
}


vector<vector<bool>> StageScreen::GetMap() {
	double antSize = 10;

	vector<vector<bool>> map(Constants::WINDOW_WIDTH, vector<bool>(Constants::WINDOW_HEIGHT, true));

	for (int i = 0; i < Constants::WINDOW_WIDTH; i++) {
		for (int j = 0; j < Constants::WINDOW_HEIGHT; j++) {
			Vector pixel(i, j);
			for (Trap* trap : StageScreen::traps) {
				Vector dis = trap->GetPosition() - pixel;
				if (dis.GetMagnitude() <= StageScreen::pizzaSize + antSize) {
					map[i][j] = false;
				}
			}

		}
	}

	return map;
}

