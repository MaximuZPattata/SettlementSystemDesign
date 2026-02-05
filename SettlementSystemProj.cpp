#include <iostream>
#include <map>
#include <vector>

enum class ResourceType
{
        Wood,
        Stone,
        Paddy,
        Food
};

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

class Building
{
private:
    
    int m_currentBuildingLevel;
    int m_maxbuildingLevel;

public:

    //---------------------------CONSTRUCTOR----------------------------

    Building() : Building(1, 1) {}

    Building(int currentLevel, int maxLevel)
        : m_currentBuildingLevel(currentLevel), m_maxbuildingLevel(maxLevel)
    {
        if (currentLevel < 0 || maxLevel <= 0 || currentLevel > maxLevel)
            throw std::logic_error("Invalid building levels");
    }

    //----------------------------DESTRUCTOR----------------------------

    virtual ~Building() = default;

    //-------------------GET PRIVATE MEMBER FUNCTIONS-------------------

    int getCurrentBuildingLevel() const
    {
        return m_currentBuildingLevel;
    }

    int getMaxBuildingLevel() const
    {
        return m_maxbuildingLevel;
    }
};

class FarmHouse : public Building
{
public:
	FarmHouse() : Building(1, 5) {}
};




int main()
{
    FarmHouse b;

    std::cout << b.getCurrentBuildingLevel() << " : " << b.getMaxBuildingLevel() << std::endl;
}