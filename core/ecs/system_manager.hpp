#pragma once

#include "../const.hpp"
#include <set>
#include <unordered_map>
#include <memory>
#include <bitset>

class System {
public:
	std::set<entity> entities;
};

class SystemManager {
private:
	std::unordered_map<const char*, Signature> signatures;
	std::unordered_map<const char*, std::shared_ptr<System>> systems;
public:
	template<typename T>
	std::shared_ptr<T> registerSystem();

	template<typename T>
	void setSignature(Signature signature);

	void entityDestroyed(entity e);

	void entitySignatureChanged(entity e, Signature signature);
};