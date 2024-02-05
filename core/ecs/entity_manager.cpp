#include "entity_manager.hpp"
#include <assert.h>

EntityManager::EntityManager() {
	for (entity e = 0; e < MAX_ENTITIES; e++)
		ID.push(e);
}

entity EntityManager::createEntity() {
	assert(!ID.empty() && "Entity count reached maximum");
	entity id = ID.front(); ID.pop();
	return id;
}

void EntityManager::destroyEntity(entity e) {
	assert(e < MAX_ENTITIES && "EntityManager::destroyEntity(): out of range");
	signatures.at(e) = 0;
	ID.push(e);
}

void EntityManager::setSignature(entity e, Signature signature) {
	signatures.at(e) = signature;
}

Signature EntityManager::getSignature(entity e) {
	assert(e < MAX_ENTITIES && "EntityManager::getSignature(): out of range");
	return signatures.at(e);
}