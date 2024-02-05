#pragma once

#include "component_array.hpp"
#include <memory>

class ComponentManager {
public:
	template<typename T>
	void registerComponent();

	template<typename T>
	componentType getComponentType();

	template<typename T>
	void addComponent(entity e, T component);

	template<typename T>
	void removeComponent(entity e);

	template<typename T>
	T& getComponent(entity e);

	void entityDestroyed(entity e);
private:
	std::unordered_map<const char*, componentType> componentTypes;
	std::unordered_map<const char*, std::shared_ptr<IComponentArray>> componentArrays;
	componentType nextComponentType; // counter (setting IDs for components)
	template <typename T>
	std::shared_ptr<ComponentArray<T>> getComponentArray();
};