// ATC_ZHANG2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>


#include "Plane.h"
#include "Display.h"
#include "ComputerSystem.h"

int main()
{
    
    
    
    ComputerSystem compSys(readFromFile());

    compSys.spawnNewPlanes();
    compSys.updateCurrentPlaneLocation();
    updateDisplay(compSys.time, compSys.currentPlaneDatas, compSys.proximityDetector());
    compSys.updateTime();

    compSys.spawnNewPlanes();
    compSys.updateCurrentPlaneLocation();
    updateDisplay(compSys.time, compSys.currentPlaneDatas, compSys.proximityDetector());
    compSys.updateTime();

    std::cout << compSys.time << std::endl;

    

    





}


