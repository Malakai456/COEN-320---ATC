#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <iostream>

class InitialPlaneData
{
public:

	int id, arrivalTime, arrivalPosX, arrivalPosY,  arrivalPosZ, arrivalVelX,  arrivalVelY, arrivalVelZ;

		InitialPlaneData(std::vector<int>);

	
	
};

std::vector<InitialPlaneData> readFromFile();