#include "component_manager.hpp"
#include <assert.h>

template <typename T>
std::shared_ptr<ComponentArray<T>> ComponentManager::getComponentArray() {
	const char* typeName = typeid(T).name();
	assert(componentTypes.find(typeName) != componentTypes.end() && "Component not registered before use");
	// return pointer of type IComponentArray
	return std::static_pointer_cast<ComponentArray<T>>(componentArrays[typeName]);
}

template<typename T>
void ComponentManager::registerComponent() {
	const char* typeName = typeid(T).name();
	assert(componentTypes.find(typeName) == componentTypes.end() && "Registering component type more than once.");
	componentTypes.insert({ typeName, nextComponentType });
	// create a ComponentArray shared pointer & add it to the component arrays map
	componentArrays.insert({ typeName, std::make_shared < ComponentArray<T>>() });
	++nextComponentType;
}

template<typename T>
componentType ComponentManager::getComponentType() {
	const char* typeName = typeid(T).name();
	assert(componentTypes.find(typeName) != componentTypes.end() && "Component not registered before use");
	return componentTypes[typeName];
}

template<typename T>
void ComponentManager::addComponent(entity e, T component) {
	getComponentArray<T>()->insertData(e, component);
}

template<typename T>
void ComponentManager::removeComponent(entity e) {
	getComponentArray<T>()->removeData(e);
}

template<typename T>
T& ComponentManager::getComponent(entity e) {
	return getComponentArray<T>()->getData(e);
}

void ComponentManager::entityDestroyed(entity e) {
	for (auto const& pair : componentArrays) {
		auto const& component = pair.second;
		component->entityDestroyed(e);
	}
}