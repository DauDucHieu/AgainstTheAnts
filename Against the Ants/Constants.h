#pragma once

#include <string>
using namespace std;

class Constants {
public:
	static string WINDOW_TITLE;
	static int WINDOW_WIDTH;
	static int WINDOW_HEIGHT;

	static enum SCREEN_STATE {
		SS_MENU, SS_STAGE, SS_END, SS_LOADING, SS_GAME_RULES, SS_GAME_ENTITIES, SS_NONE
	};

	static enum ANT_TYPE {
		AT_NORMAL, AT_SPEEDY, AT_SMART
	};

	static enum TRAP_TYPE {
		TT_POND, TT_HONEY, TT_BLACK_HOLE
	};

	static int MOUSE_X;
	static int MOUSE_Y;

	static int FPS;
	static double DELTA_TIME;
};
