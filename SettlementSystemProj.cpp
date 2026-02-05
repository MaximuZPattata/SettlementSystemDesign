#include <iostream>
#include <map>
#include <vector>


class Building // Building class
{
private:
    int m_currentBuildingLevel;
    int m_maxbuildingLevel;

public:
    virtual ~Building() = default;

    Building() : Building(0, 1) {}

    Building(int currentLevel, int maxLevel)
        : m_currentBuildingLevel(currentLevel), m_maxbuildingLevel(maxLevel)
    {
        if (currentLevel < 0 || maxLevel <= 0 || currentLevel > maxLevel)
            throw std::logic_error("Invalid building levels");
    }

    int GetCurrentBuildingLevel() const
    {
        return m_currentBuildingLevel;
    }

    int GetMaxBuildingLevel() const
    {
        return m_maxbuildingLevel;
    }
};


int main()
{
    Building b(4, 4);

    std::cout << b.GetCurrentBuildingLevel() << " : " << b.GetMaxBuildingLevel() << std::endl;
}