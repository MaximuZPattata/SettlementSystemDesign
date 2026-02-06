#include "Settlement.h"
#include "BuildingData.h"
#include "Building.h"

extern std::string_view buildingTypeToString(BuildingType type);
extern std::string_view resourceTypeToString(ResourceType type);

//------------------------------------SETTLEMENT CLASS IMPLEMENTATION------------------------------------

void Settlement::notifyOnDayAdvanced(int dayCounter)
{
	for (auto* obs : m_observersList)
		obs->onDayAdvanced(dayCounter);
}

void Settlement::notifyBuildingConstructed(BuildingType type)
{
	for (auto* obs : m_observersList)
		obs->onBuildingConstructed(type);
}

void Settlement::notifyBuildingUpgraded(BuildingType type, int level)
{
	for (auto* obs : m_observersList)
		obs->onBuildingUpgraded(type, level);
}

void Settlement::notifyResourcesChanged()
{
	for (auto* obs : m_observersList)
		obs->onResourcesChanged(m_resources.resources);
}

void Settlement::addObserver(ISettlementObserver* observer)
{
	m_observersList.push_back(observer);
}

void Settlement::consumeResources(const ResourceMap& cost)
{
	for (const auto& [resource, amount] : cost)
		m_resources.resources[resource] -= amount;

	notifyResourcesChanged();
}

void Settlement::addResources(const ResourceMap& resourceProduced)
{
	for (const auto& [resource, amount] : resourceProduced)
		m_resources.resources[resource] += amount;

	notifyResourcesChanged();
}

//---------------------------------MAJOR SETTLEMENT CLASS IMPLEMENTATION---------------------------------

void MajorSettlement::updateResourceProduction(int currentDayCounter)
{
	ResourceMap totalProduction;

	for (const auto& building : m_buildingsList)
	{
		auto type = building->getResourceProductionType();
		auto amount = building->getResourceForTheDay(currentDayCounter);

		totalProduction[type] += amount;
	}

	addResources(totalProduction);
}

void MajorSettlement::upgradeExistingBuildings()
{
	//-----------------------LOOP THROUGH ALL BUILDINGS AND CHECK IF THEY CAN BE UPGRADED-----------------------

	for (const auto& building : m_buildingsList)
	{
		//------------------------CHECK IF BUILDING IS ALREADY AT MAX LEVEL------------------------

		if (building->getCurrentBuildingLevel() >= building->getMaxBuildingLevel())
			continue;

		//----------------------------INITIALIZE VARIABLES FOR UPGRADE-----------------------------

		const auto& baseCostList = BuildingDefs.at(building->getBuildingType()).buildCost;
		ResourceMap upgradeCost;
		bool canUpgrade = true;

		//----------------------CHECK IF RESOURCES ARE SUFFICIENT FOR UPGRADE----------------------

		for (const auto& [resource, baseAmount] : baseCostList)
		{
			int requiredAmount = baseAmount * building->getCurrentBuildingLevel();

			auto it = m_resources.resources.find(resource);
			if (it == m_resources.resources.end() || it->second < requiredAmount)
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

		//----------------------------NOTIFY OBSERVERS ABOUT THE UPGRADE---------------------------

		notifyBuildingUpgraded(building->getBuildingType(), building->getCurrentBuildingLevel());
	}
}

void MajorSettlement::constructNewBuildings()
{
	for (const auto& [buildingType, definition] : BuildingDefs)
	{
		//---------------------------INITIALIZE VARIABLES FOR CONSTRUCTION-------------------------

		const ResourceMap& costToBuild = definition.buildCost;
		bool canBuild = true;

		//--------------------CHECK IF RESOURCES ARE SUFFICIENT FOR CONSTRUCTION-------------------

		for (const auto& [resource, requiredAmount] : costToBuild)
		{
			auto it = Settlement::m_resources.resources.find(resource);
			if (it == Settlement::m_resources.resources.end() || it->second < requiredAmount)
			{
				canBuild = false;
				break;
			}
		}

		if (!canBuild)
			continue;

		//---------------------CONSUME RESOURCES AND CONSTRUCTING THE BUILDING---------------------

		consumeResources(costToBuild);
		auto building = createBuilding(buildingType);
		m_buildingsList.push_back(std::move(building));

		//-------------------------NOTIFY OBSERVERS ABOUT THE CONSTRUCTION-------------------------

		notifyBuildingConstructed(buildingType);
	}
}

std::unique_ptr<Building> MajorSettlement::createBuilding(BuildingType type) //Factory method to create building based on the type
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
}

//---------------------------------MINOR SETTLEMENT CLASS IMPLEMENTATION---------------------------------

void MinorSettlement::advanceByADay(int dayCounter)
{
	if(dayCounter % m_resourceProductionInterval == 0)
		addResources(m_dailyResourceProduction);
	
	notifyOnDayAdvanced(dayCounter);
}