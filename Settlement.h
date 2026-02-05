#pragma once
#include <unordered_map>
#include <vector>
#include <memory>
#include "Building.h"
#include "BuildingData.h"

class ISettlementObserver
{
public:
    virtual ~ISettlementObserver() = default;

    virtual void onBuildingConstructed(BuildingType type) = 0;
    virtual void onBuildingUpgraded(BuildingType type) = 0;
    virtual void onResourcesChanged(const ResourceMap& newResources) = 0;
};

class Settlement
{
protected:
    GlobalResources& m_resources;
    std::vector<ISettlementObserver*> m_observers;

    void notifyBuildingConstructed(BuildingType type)
    {
        for (auto* obs : m_observers)
            obs->onBuildingConstructed(type);
    }

    void notifyResourcesChanged()
    {
        for (auto* obs : m_observers)
            obs->onResourcesChanged(m_resources.get());
    }

public:
    explicit Settlement(GlobalResources& resources) : m_resources(resources) {}
    virtual void advanceByADay(int dayCounter);
    virtual ~Settlement() = default;

    void addObserver(ISettlementObserver* observer)
    {
        m_observers.push_back(observer);
    }
};

class MajorSettlement : public Settlement
{
private:
    std::vector<std::unique_ptr<Building>> m_buildingsList;
    
    void updateResourceProduction(int currentDayCounter);
    void upgradeExistingBuildings();
    std::unique_ptr<Building> createBuilding(BuildingType type);
    void constructNewBuildings();

public:
    MajorSettlement(GlobalResources& resources) : Settlement(resources) {}
    void advanceByADay(int dayCounter) override;
};

class MinorSettlement : public Settlement
{
private:
	// Minor settlement with a fixed daily resource production(No buildings to upgrade or construct)
    ResourceMap m_dailyResourceProduction = { {ResourceType::Wood, 2}, {ResourceType::Brick, 1}, {ResourceType::Food, 1} };
	int m_resourceProductionInterval = 3;
public:
    MinorSettlement(GlobalResources& resources): Settlement(resources) {}
    void advanceByADay(int dayCounter) override;
};
