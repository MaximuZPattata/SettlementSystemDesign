#include "Settlement.h"

void MajorSettlement::UpdateResourceProduction(int currentDayCounter)
{
	for (const auto& building : m_buildingsList)
	{
		ResourceType resourceType = building->getResourceProductionType();
		int producedAmount = building->getResourceForTheDay(currentDayCounter);

		m_globalResourceCount[resourceType] += producedAmount;
	}
}