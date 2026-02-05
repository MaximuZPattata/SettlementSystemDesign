#include <iostream>
#include <map>
#include <vector>
#include "Building.h"
#include "Types.h"

class Resource
{

};


class Settlement
{
public:
    virtual ~Settlement() = default;
};

class MajorSettlement : public Settlement
{
private:
    //Resources
public:
    void ConstructNewBuildings()
    {
        //CheckIfEnoughResources
        //
    }
};

class MinorSettlement : public Settlement
{
public:
    void AdvanceDay();
};
//
//class FarmHouse : public Building
//{
//public:
//	FarmHouse() : Building(1, 5) {}
//};
//
//class Brickworks : public Building
//{
//public:
//    Brickworks() : Building(1, 4) {}
//};
//
//class LumberCamp : public Building
//{
//public:
//    LumberCamp() : Building(1, 4) {}
//};
//
//class Quarry : public Building
//{
//public:
//    Quarry() : Building(1, 3) {}
//};


int main()
{
    //FarmHouse b;

    //std::cout << b.getCurrentBuildingLevel() << " : " << b.getMaxBuildingLevel() << std::endl;
}