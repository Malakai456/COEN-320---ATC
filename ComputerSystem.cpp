#include "ComputerSystem.h"

// constructor, used to build the vector of InitialPlanes
ComputerSystem::ComputerSystem(std::vector<InitialPlaneData> plane)
{
	this->initialPlaneDatas = plane;
}



//increments Time AND CLEARS OUT CURRENTPLANE VECTOR FOR NEXT TIME CYCLE
void ComputerSystem::updateTime()
{
	++time;
	currentPlaneDatas.clear();
}


//function checks if a plane has joined the airspace at Time t and adds it to the vector of planes in Airspace, the vector of "currentPlaneData" 
void ComputerSystem::spawnNewPlanes()
{

	for (int i = 0; i < this->initialPlaneDatas.size(); i++)
	{


		InitialPlaneData elementOfPlane = this->initialPlaneDatas.at(i);  //elementOfplane = the Plane at the current index of the vector of Planes, easier to work with

		if (elementOfPlane.arrivalTime <= this->time)
		{
			CurrentPlaneData currentPlane(elementOfPlane.id, elementOfPlane.arrivalPosX, elementOfPlane.arrivalPosY, // Calling the currentPlane constructor 
				elementOfPlane.arrivalPosZ, elementOfPlane.arrivalVelX,
				elementOfPlane.arrivalVelY, elementOfPlane.arrivalVelZ);

			this->currentPlaneDatas.push_back(currentPlane);  //CurrentPlane pushed into vector of currentPlaneData, CurrentPlaneDatas
		}



	}

}

// function compare every plane see if too close and returns a vectors of of violations for every plane, ex: returns ( [][5][][][2] ) = plane 1, 3, 4 no crash, 2 crash with 5 and vice versa
std::vector<std::vector<int>> ComputerSystem::proximityDetector()
{
	std::vector<std::vector<int>> violations;
	std::vector<int> empty;

	for (int i = 0; i < currentPlaneDatas.size(); i++)
	{
		violations.push_back(empty);
	}

	for (int i = 0; i < this->currentPlaneDatas.size(); i++)
	{
		for (int j = 0; j < this->currentPlaneDatas.size(); j++) // j=i+1 because comparing current plane to next plane
		{
			if (j == i)
			{
				continue;
			}

			CurrentPlaneData plane1 = currentPlaneDatas.at(i);
			CurrentPlaneData plane2 = currentPlaneDatas.at(j);

			if (plane1.distanceBetweenPlanes(plane2) < SAFE_DISTANCE)
			{
				violations.at(i).push_back(plane2.id);
			}

		}

	}

	return violations;
}

//updates the XYZ of currentPlanes 
void ComputerSystem::updateCurrentPlaneLocation()
{
	for (int i = 0; i < this->currentPlaneDatas.size(); i++)
	{
		CurrentPlaneData elementOfCurrentPlaneDatas = this->currentPlaneDatas.at(i);  //elementOfCurrentPlane = the CurrentPlaneDatas at the index i of the vector of CurrentPlanes

		elementOfCurrentPlaneDatas.currentPosX += elementOfCurrentPlaneDatas.currentVelX * ((double)this->time - initialPlaneDatas.at(elementOfCurrentPlaneDatas.id - 1).arrivalTime);  //velocity* (time - arrival time of plane)
		elementOfCurrentPlaneDatas.currentPosY += elementOfCurrentPlaneDatas.currentVelY * ((double)this->time - initialPlaneDatas.at(elementOfCurrentPlaneDatas.id - 1).arrivalTime);  //basically accounts for planes who came at time != 0
		elementOfCurrentPlaneDatas.currentPosZ += elementOfCurrentPlaneDatas.currentVelZ * ((double)this->time - initialPlaneDatas.at(elementOfCurrentPlaneDatas.id - 1).arrivalTime);

		if (elementOfCurrentPlaneDatas.currentPosX > MAX_X || elementOfCurrentPlaneDatas.currentPosY > MAX_Y || elementOfCurrentPlaneDatas.currentPosZ > MAX_Z) // take element off vector if goes outside airspace
		{
			this->currentPlaneDatas.erase(this->currentPlaneDatas.begin() + i);

			i = (i - 1);    // gotta do this cuz taking an element off the vector pushes all vectors after that element 1 index foward, so you gotta decrement i otherwise 1 element will get skipped in the loop;         
		}
		else
		{
			this->currentPlaneDatas.at(i) = elementOfCurrentPlaneDatas;     //otherwise                                       
		}


	}
}

// constructor for Current Plane
CurrentPlaneData::CurrentPlaneData(int id, double currentPosX, double currentPosY, double currentPosZ, double currentVelX, double currentVelY, double currentVelZ)
{
	this->id = id;
	this->currentPosX = currentPosX;
	this->currentPosY = currentPosY;
	this->currentPosZ = currentPosZ;
	this->currentPosZ = currentPosZ;
	this->currentVelX = currentVelX;
	this->currentVelY = currentVelY;
	this->currentVelZ = currentVelZ;
}

// distance checker between two planes
double CurrentPlaneData::distanceBetweenPlanes(const CurrentPlaneData& other)
{
	double diffX = this->currentPosX - other.currentPosX;
	double diffY = this->currentPosY - other.currentPosY;
	double diffZ = this->currentPosZ - other.currentPosZ;
	return sqrt(diffX * diffX + diffY * diffY + diffZ * diffZ);
}

