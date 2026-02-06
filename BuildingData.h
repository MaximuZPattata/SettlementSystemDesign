#pragma once
#include <unordered_map>

//-------------------------------HARDCODING BUILDING DATA HERE!!!-------------------------------
//---------------------------SCALABLE TO ADD MORE TYPES IN THE FUTURE---------------------------

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

//A map to represent the amount of each resource type, used for both construction costs and resource production
using ResourceMap = std::unordered_map<ResourceType, int>;

struct BuildingDefinition
{
    ResourceMap buildCost;
};

class GlobalResources
{
public:
    ResourceMap resources = {};
};

//Initializing the building definitions with their respective construction costs
extern const std::unordered_map<BuildingType, BuildingDefinition> BuildingDefs; 
