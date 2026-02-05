#include <iostream>
#include <limits>
#include <string>
#include "Building.h"
#include "BuildingData.h"
#include "Settlement.h"


int main()
{
	int dayCounter = 0;
	Settlement* bigSettlement = new MajorSettlement();
	Settlement* smallSettlement = new MinorSettlement();
    

    while (true)
    {
        std::cout << "Press ENTER to advance day. Type Q + ENTER to quit.\n";
        std::string input;
        std::getline(std::cin, input);

        if (input == "Q")
            break;

        bigSettlement->advanceByADay(dayCounter);
        smallSettlement->advanceByADay(dayCounter);
        dayCounter++;

        std::cout << "-------------------------------------------------------------------------------\n";
    }
}