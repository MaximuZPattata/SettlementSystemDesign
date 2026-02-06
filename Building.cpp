#include "Building.h"

extern std::string_view buildingTypeToString(BuildingType type);

//----------------------------OTHER MEMBER FUNCTION IMPLEMENTATION-----------------------------

int Building::getCurrentBuildingLevel() const
{
	return m_currentBuildingLevel;
}

int Building::getMaxBuildingLevel() const
{
	return m_maxbuildingLevel;
}

int Building::getResourceForTheDay(int dayCounter)
{
	if (dayCounter % m_resourceProductionInterval == 0)
		return m_resourceProductionAmount;
	else
		return 0;
}

ResourceType Building::getResourceProductionType() const
{
	return m_resourceProduction;
}

BuildingType Building::getBuildingType() const
{
	return m_buildingType;
}

//-----------------------------GET MEMBER FUNCTION IMPLEMENTATION------------------------------

bool Building::canUpgradeBuilding(const ResourceMap& resourcesAvailable) const
{
	if (m_currentBuildingLevel >= m_maxbuildingLevel)
		return false;

	const auto& baseCostList = BuildingDefs.at(m_buildingType).buildCost;
	
	for (const auto& [resource, baseAmount] : baseCostList)
	{
		int requiredAmount = baseAmount * m_currentBuildingLevel;

		auto it = resourcesAvailable.find(resource);
		if (it == resourcesAvailable.end() || it->second < requiredAmount)
			return false;
	}

	return true;
}

void Building::upgradeBuildingAndResourceProduction()
{
	m_currentBuildingLevel++;
	m_resourceProductionAmount += 2;
}
