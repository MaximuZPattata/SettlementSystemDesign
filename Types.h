#pragma once

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
