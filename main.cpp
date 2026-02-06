#include <iostream>
#include <limits>
#include <string>
#include "Building.h"
#include "BuildingData.h"
#include "Settlement.h"
#include "AnyUI.h"


int main()
{
	int dayCounter = 0;
    GlobalResources globalResources;
	AnyUI uiObserver;
	globalResources.resources = { { ResourceType::Wood,  10 }, { ResourceType::Stone, 10 }, { ResourceType::Brick, 10 }, { ResourceType::Food, 10 } };

    MajorSettlement major(globalResources);
    MinorSettlement minor(globalResources);
	major.addObserver(&uiObserver);

    while (true)
    {
        std::cout << "Press ENTER to advance day. Type Q + ENTER to quit.\n";
        std::string input;
        std::getline(std::cin, input);

        if (input == "Q" || input == "q")
            break;

        major.advanceByADay(dayCounter);
        minor.advanceByADay(dayCounter);
        dayCounter++;

        std::cout << "-------------------------------------------------------------------------------\n";
    }
}