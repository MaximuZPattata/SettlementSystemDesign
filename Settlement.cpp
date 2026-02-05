#include "Settlement.h"
#include "BuildingData.h"
#include "Building.h"

extern std::string_view buildingTypeToString(BuildingType type);
extern std::string_view resourceTypeToString(ResourceType type);

void Settlement::advanceByADay(int dayCounter)
{
	std::cout << "Settlement advanced by a day. Current day: " << dayCounter << std::endl;
	std::cout << "Current resources: \n";

	for (const auto& [resource, amount] : m_globalResourceCount)
		std::cout << resourceTypeToString(resource) << ": " << amount << std::endl;
}

void MajorSettlement::consumeResources(const ResourceMap& cost)
{
	for (const auto& [resource, amount] : cost)
		m_globalResourceCount[resource] -= amount;
}

void MajorSettlement::updateResourceProduction(int currentDayCounter)
{
	for (const auto& building : m_buildingsList)
	{
		ResourceType resourceType = building->getResourceProductionType();
		int producedAmount = building->getResourceForTheDay(currentDayCounter);

		m_globalResourceCount[resourceType] += producedAmount;
	}
}

void MajorSettlement::upgradeExistingBuildings()
{
	//-----------------------LOOP THROUGH ALL BUILDINGS AND CHECK IF THEY CAN BE UPGRADED-----------------------

	for (const auto& building : m_buildingsList)
	{
		//------------------------CHECK IF BUILDING IS ALREADY AT MAX LEVEL------------------------

		if (building->getCurrentBuildingLevel() >= building->getMaxBuildingLevel())
		{
			std::cout << buildingTypeToString(building->getBuildingType()) << " is already at MAX level!!" << std::endl;
			continue;
		}
		//----------------------------INITIALIZE VARIABLES FOR UPGRADE-----------------------------

		const auto& baseCostList = BuildingDefs.at(building->getBuildingType()).buildCost;
		ResourceMap upgradeCost;
		bool canUpgrade = true;

		//----------------------CHECK IF RESOURCES ARE SUFFICIENT FOR UPGRADE----------------------

		for (const auto& [resource, baseAmount] : baseCostList)
		{
			int requiredAmount = baseAmount * building->getCurrentBuildingLevel();

			auto it = m_globalResourceCount.find(resource);
			if (it == m_globalResourceCount.end() || it->second < requiredAmount)
			{
				canUpgrade = false;
				break;
			}

			upgradeCost[resource] = requiredAmount;
		}

		if (!canUpgrade)
			continue;

		//--------------------------CONSUME RESOURCES AND UPGRADE BUILDING-------------------------
		
		consumeResources(upgradeCost);
		building->upgradeBuildingAndResourceProduction();
	}
}

void MajorSettlement::constructNewBuildings()
{
	for (const auto& [buildingType, definition] : BuildingDefs)
	{
		const ResourceMap& costToBuild = definition.buildCost;
		bool canBuild = true;

		for (const auto& [resource, requiredAmount] : costToBuild)
		{
			auto it = m_globalResourceCount.find(resource);
			if (it == m_globalResourceCount.end() || it->second < requiredAmount)
				canBuild = false;
		}

		if (!canBuild)
			continue;
		
		consumeResources(costToBuild);

		auto building = createBuilding(buildingType);
		m_buildingsList.push_back(std::move(building));

		std::cout << "Constructed new " << buildingTypeToString(buildingType) << "!" << std::endl;
	}
}

std::unique_ptr<Building> MajorSettlement::createBuilding(BuildingType type)
{
	switch (type)
	{
	case BuildingType::Farmhouse:
		return std::make_unique<FarmHouse>();

	case BuildingType::Brickworks:
		return std::make_unique<Brickworks>();

	case BuildingType::LumberCamp:
		return std::make_unique<LumberCamp>();

	case BuildingType::Quarry:
		return std::make_unique<Quarry>();

	default:
		throw std::runtime_error("Unknown BuildingType");
	}
}

void MajorSettlement::advanceByADay(int dayCounter)
{
	updateResourceProduction(dayCounter);
	upgradeExistingBuildings();
	constructNewBuildings();

	Settlement::advanceByADay(dayCounter);
}

void MinorSettlement::advanceByADay(int dayCounter)
{
	if(dayCounter % m_resourceProductionInterval == 0)
	{
		for (const auto& [resource, amount] : m_dailyResourceProduction)
			m_globalResourceCount[resource] += amount;
	}
	
	Settlement::advanceByADay(dayCounter);
}