#pragma once

#include "../const.hpp"
#include <array>
#include <unordered_map>

class IComponentArray {
public:
	virtual ~IComponentArray() = default;
	virtual void entityDestroyed(entity e) = 0;
};

template<typename T>
class ComponentArray : public IComponentArray {
private:
	// just a wrapper of original arrays
	std::array<T, MAX_ENTITIES> componentArray;
	// better than arrays because search time is O(1)
	std::unordered_map<entity, size_t> entityToIndex;
	size_t arraySize;
public:
	void insertData(entity e, T component);
	void removeData(entity e);
	T& getData(entity e);
	void entityDestroyed(entity e) override;
};