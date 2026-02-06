#pragma once
#include <unordered_map>
#include <vector>
#include <memory>
#include "Building.h"
#include "BuildingData.h"
#include "ObserverInterface.h"

//-------------------------------SETTLEMENT CLASS DEFINITIONS--------------------------------

class Settlement
{
protected:
    GlobalResources& m_resources;

	//-----OBSERVER MEMBER VARIABLE AND FUNCTIONS TO NOTIFY THE UI ABOUT CHANGES IN THE SETTLEMENT-----

    std::vector<ISettlementObserver*> m_observersList;

    void notifyOnDayAdvanced(int dayCounter);
    void notifyBuildingConstructed(BuildingType type);
    void notifyBuildingUpgraded(BuildingType type, int level);
    void notifyResourcesChanged();

public:
    Settlement(GlobalResources& resources) : m_resources(resources) {}
    virtual void advanceByADay(int dayCounter) = 0;
    void addResources(const ResourceMap&);
    void consumeResources(const ResourceMap&);
    void addObserver(ISettlementObserver* observer);
    virtual ~Settlement() = default;
};

//----------------------------MAJOR SETTLEMENT CLASS DEFINITIONS-----------------------------

class MajorSettlement : public Settlement
{
private:
    std::vector<std::unique_ptr<Building>> m_buildingsList;
    
    void updateResourceProduction(int currentDayCounter);
    void upgradeExistingBuildings();
    std::unique_ptr<Building> createBuilding(BuildingType type); //Factory method to create building based on the type
    void constructNewBuildings();

public:
	MajorSettlement(GlobalResources& resources) : Settlement(resources) {}
    void advanceByADay(int dayCounter) override;
};

//----------------------------MINOR SETTLEMENT CLASS DEFINITIONS-----------------------------

class MinorSettlement : public Settlement
{
private:
	// Minor settlement with a fixed daily resource production(No buildings to upgrade or construct)
    ResourceMap m_dailyResourceProduction = { {ResourceType::Wood, 2}, {ResourceType::Brick, 1}, {ResourceType::Food, 1} };
	int m_resourceProductionInterval = 3;
public:
    MinorSettlement(GlobalResources& resources) : Settlement(resources) {}
    void advanceByADay(int dayCounter) override;
};
