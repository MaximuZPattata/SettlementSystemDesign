#pragma once

class ISettlementObserver
{
public:
    virtual ~ISettlementObserver() = default;

	virtual void onDayAdvanced(int dayCounter) = 0;
    virtual void onBuildingConstructed(BuildingType type) = 0;
    virtual void onBuildingUpgraded(BuildingType type, int level) = 0;
    virtual void onResourcesChanged(const ResourceMap& newResources) = 0;
};

