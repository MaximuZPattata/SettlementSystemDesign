#pragma once
#include <unordered_map>
#include <vector>
#include <memory>
#include "Building.h"
#include "BuildingData.h"

class Settlement
{
public:
    virtual ~Settlement() = default;
    void AdvanceDay();
};

class MajorSettlement : public Settlement
{
private:
	ResourceMap m_globalResourceCount;
    std::vector<std::unique_ptr<Building>> m_buildingsList;

public:
	void UpdateResourceProduction(int currentDayCounter);
    void ConstructNewBuildings();
};

class MinorSettlement : public Settlement
{
private:
	// Fixed resource production for minor settlements at fixed intervals
public:
    void AdvanceDay();
};
