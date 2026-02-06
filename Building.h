#pragma once
#include <iostream>
#include "BuildingData.h"

//Base Building Class
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
    int getResourceForTheDay(int dayCounter);
    BuildingType getBuildingType() const;
    ResourceType getResourceProductionType() const;

	//------------------OTHER BUILDING INFO FUNCTIONS-------------------

    bool canUpgradeBuilding(const ResourceMap& resourcesAvailable) const;
	void upgradeBuildingAndResourceProduction();
};

//-----------------HARDCODING DEFAULT BUILDING DATA IN THE CONSTRUCTORS OF THESE CLASSES-----------------
//--------------------------SCALABLE TO ADD MORE BUILDING TYPES IN THE FUTURE----------------------------

class FarmHouse : public Building
{
public:
    FarmHouse() : Building(1, 5, 2, 2, ResourceType::Food, BuildingType::Farmhouse) {}
};

class Brickworks : public Building
{
public:
    Brickworks() : Building(1, 4, 2, 3, ResourceType::Brick, BuildingType::Brickworks) {}
};

class LumberCamp : public Building
{
public:
    LumberCamp() : Building(1, 4, 1, 1, ResourceType::Wood, BuildingType::LumberCamp) {}
};

class Quarry : public Building
{
public:
    Quarry() : Building(1, 3, 3, 2, ResourceType::Stone, BuildingType::Quarry) {}
};

