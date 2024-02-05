#include "coordinator.hpp"

void Coordinator::init() {
	// create unique pointers to each manager
	componentManager = std::make_unique<ComponentManager>();
	entityManager = std::make_unique<EntityManager>();
	systemManager = std::make_unique<SystemManager>();
}

entity Coordinator::createEntity() {
	return entityManager->createEntity();
}

void Coordinator::destroyEntity(entity e) {
	entityManager->destroyEntity(e);
	componentManager->entityDestroyed(e);
	systemManager->entityDestroyed(e);
}

