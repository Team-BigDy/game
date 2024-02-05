#pragma once

#include "component_manager.hpp"
#include "system_manager.hpp"
#include "entity_manager.hpp"

class Coordinator {
private:
	std::unique_ptr<ComponentManager> componentManager;
	std::unique_ptr<EntityManager> entityManager;
	std::unique_ptr<SystemManager> systemManager;

public:
	void init();
	entity createEntity();
	void destroyEntity(entity e);

	// component methods
	template <typename T>
	void registerComponent();

	template <typename T>
	void addComponent(entity e, T component);

	template <typename T>
	T& getComponent(entity e);

	template <typename T>
	componentType getComponentType();

	// system methods
	template <typename T>
	std::shared_ptr<T> registerSystem();

	template <typename T>
	void setSystemSignature(Signature signature);
};

#include "coordinator.inl"