#pragma once

#include "../const.hpp"
#include <queue>
#include <array>

class EntityManager {
private:
	std::queue<entity> ID;
	std::array<Signature, MAX_ENTITIES> signatures;
public:
	EntityManager();
	entity createEntity();
	void destroyEntity(entity e);
	void setSignature(entity e, Signature signature);
	Signature getSignature(entity e);
};