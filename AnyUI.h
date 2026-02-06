#pragma once
#include "Settlement.h"

extern std::string_view buildingTypeToString(BuildingType type);
extern std::string_view resourceTypeToString(ResourceType type);

class AnyUI : public ISettlementObserver
{
public:
	void onDayAdvanced(int dayCounter) override;
    void onBuildingConstructed(BuildingType type) override;
    void onBuildingUpgraded(BuildingType type, int level) override;
    void onResourcesChanged(const ResourceMap& resources) override;
};

