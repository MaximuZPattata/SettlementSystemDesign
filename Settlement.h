#pragma once
#include <unordered_map>
#include <vector>
#include <memory>
#include "Building.h"
#include "BuildingData.h"

class Settlement
{
public:
    ResourceMap m_globalResourceCount;
    virtual void advanceByADay(int dayCounter) = 0;
    virtual ~Settlement() = default;
};

class MajorSettlement : public Settlement
{
private:
    std::vector<std::unique_ptr<Building>> m_buildingsList;
    
    void consumeResources(const ResourceMap& cost);
    void updateResourceProduction(int currentDayCounter);
    void upgradeExistingBuildings();
    std::unique_ptr<Building> createBuilding(BuildingType type);
    void constructNewBuildings();

public:
    void advanceByADay(int dayCounter) override;
};

class MinorSettlement : public Settlement
{
private:
	// Minor settlements have a fixed daily resource production and no buildings to upgrade or construct.
    ResourceMap m_dailyResourceProduction = { {ResourceType::Wood, 2}, {ResourceType::Brick, 1}, {ResourceType::Food, 1} };
	int m_resourceProductionInterval = 3;
public:
    void advanceByADay(int dayCounter) override;
};
