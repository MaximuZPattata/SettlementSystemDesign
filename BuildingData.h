#pragma once
#include <unordered_map>

//-------------------------------HARDCODING BUILDING DATA HERE!!!-------------------------------

enum class ResourceType
{
    Wood,
    Stone,
    Brick,
    Food
};

enum class BuildingType
{
    Farmhouse,
    Brickworks,
    LumberCamp,
    Quarry
};

struct ResourceCost
{
    ResourceType type;
    int amount;
};

using ResourceMap = std::unordered_map<ResourceType, int>;

struct BuildingDefinition
{
    ResourceMap buildCost;
};

extern const std::unordered_map<BuildingType, BuildingDefinition> BuildingDefs;
