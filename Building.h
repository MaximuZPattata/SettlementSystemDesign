#pragma once
#include <iostream>
#include "Types.h"

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

    int getCurrentBuildingLevel() const;

    int getMaxBuildingLevel() const;
};

