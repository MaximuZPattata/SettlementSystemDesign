#include "Building.h"

extern std::string_view toString(ResourceType type);

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

ResourceType Building::getResourceProductionType() const
{
	return m_resourceProduction;
}

void Building::upgradeBuildingAndResourceProduction(const ResourceMap& resourcesAvailable)
{
	if (canUpgradeBuilding(resourcesAvailable))
	{
		m_currentBuildingLevel++;
		m_resourceProductionAmount += 2;
	}
	else if(m_currentBuildingLevel >= m_maxbuildingLevel)
		std::cout << toString(m_resourceProduction) << " is already at max level!" << std::endl;
	else
		std::cout << "Not enough resources to upgrade " << toString(m_resourceProduction) << "!" << std::endl;
}
