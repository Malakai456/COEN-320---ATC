#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

#include "Plane.h"


class CurrentPlaneData;

class ComputerSystem

{
public:

	int time = 0;
	int SAFE_DISTANCE = 20;

	std::vector<InitialPlaneData> initialPlaneDatas;
    std::vector<CurrentPlaneData> currentPlaneDatas;

	ComputerSystem(std::vector<InitialPlaneData> plane);

	void spawnNewPlanes();
	void updateTime();

	std::vector<std::vector<int>> proximityDetector();
	void updateCurrentPlaneLocation();



};


class CurrentPlaneData
{
public:
	int id;
	double currentPosX, currentPosY, currentPosZ, currentVelX, currentVelY, currentVelZ;

	CurrentPlaneData(int id, double currentPosX, double currentPosY, double currentPosZ, double currentVelX, double currentVelY, double currentVelZ);

	double distanceBetweenPlanes(const CurrentPlaneData& other);
};
