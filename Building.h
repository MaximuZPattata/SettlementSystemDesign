#pragma once
#include <iostream>
#include "BuildingData.h"

class Building
{
private:

    int m_currentBuildingLevel;
    int m_maxbuildingLevel;
    int m_resourceProductionAmount;
    int m_resourceProductionInterval;
    ResourceType m_resourceProduction;
    BuildingType m_buildingType;

public:

    //---------------------------CONSTRUCTOR----------------------------

    Building(int currentLevel, int maxLevel, int resourceProdAmount, int resourceProdInterval, 
        ResourceType resourceType, BuildingType buildType)
        : m_currentBuildingLevel(currentLevel), m_maxbuildingLevel(maxLevel), m_resourceProductionAmount(resourceProdAmount), 
        m_resourceProductionInterval(resourceProdInterval), m_resourceProduction(resourceType),
        m_buildingType(buildType)
    {
        if (currentLevel < 0 || maxLevel <= 0 || currentLevel > maxLevel)
            throw std::logic_error("Invalid building levels");
    }

    //----------------------------DESTRUCTOR----------------------------

    virtual ~Building() = default;

    //-------------------GET PRIVATE MEMBER FUNCTIONS-------------------

    int getCurrentBuildingLevel() const;
    int getMaxBuildingLevel() const;
	ResourceType getResourceProductionType() const;
	int getResourceForTheDay(int dayCounter);
    bool canUpgradeBuilding(const ResourceMap& resourcesAvailable) const;
	void upgradeBuildingAndResourceProduction(const ResourceMap& resourcesAvailable);
};

