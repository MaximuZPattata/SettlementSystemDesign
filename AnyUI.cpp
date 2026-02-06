#include "AnyUI.h"

void AnyUI::onDayAdvanced(int dayCounter)
{
    std::cout << "Settlement advanced by a day. Current day: " << dayCounter << std::endl;
}

void AnyUI::onBuildingConstructed(BuildingType type)
{
    std::cout << "Built: " << buildingTypeToString(type) << " !!\n";
}

void AnyUI::onBuildingUpgraded(BuildingType type, int level)
{
	std::cout << "Upgraded: " << buildingTypeToString(type) << " to level " << level << " !!\n";
}

void AnyUI::onResourcesChanged(const ResourceMap& resources)
{
    std::cout << "Resources updated:\n";

    for (const auto& [resource, amount] : resources)
        std::cout << "  " << resourceTypeToString(resource) << " : " << amount << "\n";
}