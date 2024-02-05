#pragma once

#include <memory>
#include "../sys/movement_system.hpp"
#include "../sys/animation_system.hpp"
#include "../sys/keyboard_system.hpp"
#include "state_manager.hpp"

class Game {

public:
	Game() {
		memset(playingKeys, 0, sizeof(playingKeys));
	}
	~Game() {}

	void init(const char* title, int x, int y, int w, int h, int flags);
	void handleEvents();
	void update();
	void render();
	void clean();
	
	bool running() { return isRunning; }

private:
	bool isRunning;
	SDL_Window* window;
	SDL_Event ev;
	SDL_Renderer* renderer;
	std::shared_ptr<MovementSystem> movementSystem;
	std::shared_ptr<AnimationSystem> animationSystem;
	std::shared_ptr<KeyboardSystem> keyboardSystem;
	entity player;
};