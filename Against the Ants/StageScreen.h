#pragma once

#include "GameManager.h"
#include "LoadingScreen.h"

#include "Constants.h"
#include "SDLConstants.h"
#include "Draw.h"

#include "NormalAnt.h"
#include "SpeedyAnt.h"
#include "SmartAnt.h"

#include "TrapPond.h"
#include "TrapHoney.h"
#include "TrapBlackHole.h"

#include "EndScreen.h"

#include "Random.h"

#include <vector>

class StageScreen {
private:
	static vector<Ant*> ants;
	static vector<Trap*> traps;

	static double winTimeLimit;
	static double winTime;

	static double trapRadius;
	static Vector trapIconPosition;
	static int trapIconRadius;
	static bool isTraping;

	static Vector unableTrapPosition;
	static int unableTrapRadius;

	static double trapAbleDelay;
	static double trapAbleTime;
	static bool isTrapable;

	static Vector pizzaPosition;
	static int pizzaSize;
	
	static Ant* antBringPizza;

	static int antHpDown;
	static int trapHpDown;

	static int normalAntRate;
	static int speedyAntRate;
	static int smartAntRate;

	static int pondTrapRate;
	static int honeyTrapRate;
	static int blackHoleTrapRate;
	static double randomTrapRateDelay;
	static double randomTrapRateTime;

	static Vector spawnPosition;
	static double spawnAntDelay;
	static double spawnAntTime;

	static Constants::ANT_TYPE GetRandAntType();
	static Constants::TRAP_TYPE GetRandTrapType();
	
	static void RandomTrapRate();
	static void RenderTrapRate();
	static void TrapEffectToAnt();
	static bool IsInUnableTrapingRange();

	static void RenderBgImage();
	static void RenderTraps();
	static void RenderAnts();
	static void RenderPizza();
	static void RenderUnableTrap();
	static void RenderTraping();
	static void RenderTrapingTimeBar();
	static void RenderWinTimeBar();

	static void DeleteDeadAnts();
	static void DeleteDeadTraps();
	static void UpdateAnts();
	static void UpdateTraps();
	static void BringPizza();
	static void UpdateTraping();
	static void UpdateWinTime();

public:
	static bool isReset;
	static void Render();
	static void Update();
	static void HandleEvent(SDL_Event e);
	static void SpawnAnt();
	static void AddTrap(
		double addX, double addY, 
		Constants::TRAP_TYPE trapType = Constants::TT_POND
	);

	static void Reset();
};

