#  		Settlement System Design

 		A console-based settlement simulation written in modern C++, focused on game system design rather than visuals.



\# Features Implemented:

1. Major \& Minor Settlements

 	- Share a global resource pool

 	- Major settlement - construct and upgrade buildings

 	- Minor settlement produces fixed resources at stipulated intervals(Values are hardcoded)

 	- By default, the system has only 1 major and 1 minor settlement.

 	- More buildings can be constructed through a major settlement.



2\. Buildings(Building Type Hardcoded | Used Factory design concept)

 	- Level-based upgrades

 	- Resource production and costs

 	- Building types are hardcoded



3\. Resources(Hardcoded)

 	- Wood, Stone, Brick, Food



4\. Event notifications(Used Interface design concept)

 	- Building constructed

 	- Building upgraded

 	- Resources changed



5\. Bonus

 	- By pressing Enter, a day advances in the game

 	- Events are updated every day



\## How to Run



1. Build with C++17+ (Visual Studio recommended)

2\. Run the program

3\. Press ENTER to advance a day

4\. Press Q + ENTER to quit



\### Notes



1. For demonstration purposes, have used the console for UI.
2. Have used different .cpp and .h files for a better organized look.
3. The project code will have a few comments on it to understand the code better :)
