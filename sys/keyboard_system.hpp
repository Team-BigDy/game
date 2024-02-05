#pragma once

// system_manager has already been included in 'coordinator.hpp'
#include "../core/ecs/coordinator.hpp"
#include <SDL.h>

// Update keyboard input
class KeyboardSystem : public System {
public:
	void update(SDL_Event ev);
};
