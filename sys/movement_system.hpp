#pragma once

// system_manager has already been included in 'coordinator.hpp'
#include "../core/ecs/coordinator.hpp"
#include <SDL.h>

extern Coordinator game_manager;

class MovementSystem : public System {
public:
	void update(SDL_Event ev);
};