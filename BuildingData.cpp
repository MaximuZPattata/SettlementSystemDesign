#include "BuildingData.h"


//-------------------------------HARDCODE BUILDING DATA HERE!!!-------------------------------

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
        { { {ResourceType::Stone, 2}, {ResourceType::Food, 4} } }
    },
    {
        BuildingType::Quarry,
        { { {ResourceType::Food, 3}, {ResourceType::Wood, 3}, {ResourceType::Brick, 3} } }
    }
};