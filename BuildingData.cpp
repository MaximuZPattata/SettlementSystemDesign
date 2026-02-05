#include "BuildingData.h"
#include <string_view>

//-------------------------------HARDCODING BUILDING DATA HERE!!!-------------------------------

const std::unordered_map<BuildingType, BuildingDefinition> BuildingDefs =
{
    {
        BuildingType::Farmhouse,
        { { {ResourceType::Stone, 1}, {ResourceType::Brick, 5} } }
    },
    {
        BuildingType::Brickworks,
        { { {ResourceType::Wood, 2}, {ResourceType::Stone, 3} } }
    },
    {
        BuildingType::LumberCamp,
        { { {ResourceType::Brick, 2}, {ResourceType::Food, 3} } }
    },
    {
        BuildingType::Quarry,
        { { {ResourceType::Food, 3}, {ResourceType::Wood, 3}, {ResourceType::Brick, 3} } }
    }
};

std::string_view buildingTypeToString(BuildingType type)
{
    switch(type)
    {
    case BuildingType::LumberCamp:  return "LumberCamp";
    case BuildingType::Farmhouse:  return "Farmhouse";
    case BuildingType::Brickworks: return "Brickworks";
    case BuildingType::Quarry: return "Quarry";
    default:                  return "Unknown";
    }
}

std::string_view resourceTypeToString(ResourceType type)
{
    switch (type)
    {
    case ResourceType::Wood:  return "Wood";
    case ResourceType::Food:  return "Food";
    case ResourceType::Brick: return "Brick";
    case ResourceType::Stone: return "Stone";
    default:                  return "Unknown";
    }
}