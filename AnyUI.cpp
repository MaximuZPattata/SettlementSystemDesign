#include "AnyUI.h"

//-----------------IMPLEMENTATION CAN BE REPLACED BY ANY UI HERE-------------------------
//-----------------PRINTING TO CONSOLE FOR DEMONSTRATION PURPOSES------------------------

void AnyUI::onDayAdvanced(int dayCounter)
{
    std::cout << "\nSettlement advanced by a day. Current day: " << dayCounter << std::endl;
}

void AnyUI::onBuildingConstructed(BuildingType type)
{
    std::cout << "\nBuilt: " << buildingTypeToString(type) << " !!\n";
}

void AnyUI::onBuildingUpgraded(BuildingType type, int level)
{
	std::cout << "\nUpgraded: " << buildingTypeToString(type) << " to level " << level << " !!\n";
}

void AnyUI::onResourcesChanged(const ResourceMap& resources)
{
    std::cout << "\nResources updated:\n";

    for (const auto& [resource, amount] : resources)
        std::cout << "  " << resourceTypeToString(resource) << " : " << amount << "\n";
}