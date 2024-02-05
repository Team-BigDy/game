#include "coordinator.hpp"

template<typename T>
void Coordinator::registerComponent() {
	componentManager->registerComponent<T>();
}

template<typename T>
void Coordinator::addComponent(entity e, T component) {
	componentManager->addComponent(e, component);
	auto signature = entityManager->getSignature(e);
	// set property: componentManager->getComponentType() of type T
	signature.set(componentManager->getComponentType<T>(), true);
	entityManager->setSignature(e, signature);
	// called when add a component
	systemManager->entitySignatureChanged(e, signature);
}

template<typename T>
T& Coordinator::getComponent(entity e) {
	// get all components of e
	return componentManager->getComponent<T>(e);
}

template<typename T>
componentType Coordinator::getComponentType() {
	// get ID for component type T
	return componentManager->getComponentType<T>();
}

template<typename T>
std::shared_ptr<T> Coordinator::registerSystem() {
	return systemManager->registerSystem<T>();
}

template<typename T>
void Coordinator::setSystemSignature(Signature signature) {
	systemManager->setSignature<T>(signature);
}