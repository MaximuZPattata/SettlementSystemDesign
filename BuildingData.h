#pragma once
#include <unordered_map>
#include "Types.h"

using ResourceMap = std::unordered_map<ResourceType, int>;

struct BuildingDefinition
{
    ResourceMap buildCost;
};

extern const std::unordered_map<BuildingType, BuildingDefinition> BuildingDefs;
