#pragma once

#include <cstdint> // for std::uint32_t
#include <bitset>

typedef std::uint32_t entity;
typedef std::uint8_t componentType;

const componentType MAX_COMPONENTS = 32;

typedef std::bitset<MAX_COMPONENTS> Signature;

const entity MAX_ENTITIES = 5000;
const int MAX_PLAYING_KEYS = 5;

const int FPS = 60;
const int frameDelay = 1000 / FPS;
const int SPRINT_SPEED = 5;