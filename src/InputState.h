/*
Copyright © 2011-2012 Clint Bellanger

This file is part of FLARE.

FLARE is free software: you can redistribute it and/or modify it under the terms
of the GNU General Public License as published by the Free Software Foundation,
either version 3 of the License, or (at your option) any later version.

FLARE is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
FLARE.  If not, see http://www.gnu.org/licenses/
*/

#ifndef INPUT_STATE_H
#define INPUT_STATE_H

#include "FileParser.h"
#include "Utils.h"
#include "UtilsParsing.h"
#include "Settings.h"

#include <SDL.h>
#include <string>


#define JOY_DEADZONE	100

#define JOY_POS_CENTER	0
#define JOY_POS_LEFT	-1
#define JOY_POS_RIGHT	1
#define JOY_POS_UP	-1
#define JOY_POS_DOWN	1


// Input commands enum
enum {
	CANCEL,
	ACCEPT,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	BAR_1,
	BAR_2,
	BAR_3,
	BAR_4,
	BAR_5,
	BAR_6,
	BAR_7,
	BAR_8,
	BAR_9,
	BAR_0,
	CHARACTER,
	INVENTORY,
	POWERS,
	LOG,
	MAIN1,
	MAIN2,
	CTRL,
	SHIFT,
	DEL,
	PAUSE,
	LAST_KEY
};

/**
 * class InputState
 *
 * Handles keyboard and mouse states
 */

class InputState {
private:
	static const int key_count = LAST_KEY;
	int binding[key_count];
	int binding_alt[key_count];
public:
	InputState(void);
	~InputState();
	void loadKeyBindings();
	void saveKeyBindings();
	void handle();

	bool pressing[key_count];
	bool lock[key_count];
	
	bool done;
	Point mouse;
	std::string inkeys;
};

#endif
