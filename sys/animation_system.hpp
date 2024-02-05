#pragma once

// system_manager has already been included in 'coordinator.hpp'
#include "../core/ecs/coordinator.hpp"
#include <SDL.h>

extern Coordinator game_manager;

class AnimationSystem : public System {

public:
	void update();
	void render(SDL_Renderer* ren);
};