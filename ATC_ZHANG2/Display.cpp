#include "Display.h"

\
std::string vector_to_string(const std::vector<int>& v)
{
	std::string result = "[";
	if (v.size() > 0)
	{
		for (int i = 0; i < v.size() - 1; i++)
		{
			result += std::to_string(v.at(i)) + ", ";
		}
		result += std::to_string(v.at(v.size() - 1));
	}
	result += "]";
	return result;
}


void updateDisplay(int time, std::vector<CurrentPlaneData> currentPlanes, std::vector<std::vector<int>> violations)
{
	std::cout << "Time: " << time << "               X       Y       Z        VelX     VelY     VelZ     Proximity" << std::endl;

	for (int i = 0; i < currentPlanes.size(); i++)
	{
		CurrentPlaneData plane = currentPlanes.at(i);
		std::vector<int> violation = violations.at(i);

		std::cout << "Plane: " << plane.id << "\t  " << plane.currentPosX << "\t" << plane.currentPosY << "\t" <<
			plane.currentPosZ << "\t \t" << plane.currentVelX << "\t " << plane.currentVelY << "\t " << plane.currentVelZ
			<< "\t   " << vector_to_string(violation) << std::endl;
	}


}