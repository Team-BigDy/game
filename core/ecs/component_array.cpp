#include "component_array.hpp"
#include <assert.h>

template<typename T>
void ComponentArray<T>::insertData(entity e, T component) {
	assert(entityToIndex.find(e) == entityToIndex.end() && "Component of entity existed");
	size_t newIndex = arraySize;
	entityToIndex[e] = newIndex;
	componentArray[newIndex] = component;
	++arraySize;
}

template<typename T>
void ComponentArray<T>::removeData(entity e) {
	assert(entityToIndex.find(e) != entityToIndex.end() && "Removing non-existent component");
	// copy element at end into the place of the deleted element to maintain density
	size_t indexOfRemovedElement = entityToIndex[e];
	componentArray[indexOfRemovedElement] = componentArray[arraySize - 1];
	// update map
	entityToIndex[arraySize - 1] = indexOfRemovedElement; // TODO?
	entityToIndex.erase(e);
	--arraySize;
}

template<typename T>
T& ComponentArray<T>::getData(entity e) {
	assert(entityToIndex.find(e) != entityToIndex.end() && "Retrieving non-existent component");
	// return entityToIndex[e]-th element of type T of componentArray[]
	return componentArray[entityToIndex[e]];
}

// redefining virtual method
template<typename T>
void ComponentArray<T>::entityDestroyed(entity e) {
	if (entityToIndex.find(e) != entityToIndex.end())
		removeData(e);
}