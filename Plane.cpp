#include "Plane.h"

//plane constructor
InitialPlaneData::InitialPlaneData(std::vector<int> data)
{


	this->id = data.at(0);
	this->arrivalTime = data.at(1);
	this->arrivalPosX = data.at(2);
	this->arrivalPosY = data.at(3);
	this->arrivalPosZ = data.at(4);
	this->arrivalVelX = data.at(5);
	this->arrivalVelY = data.at(6);
	this->arrivalVelZ = data.at(7);


}

// reads from input file, returns a vector of InitialPlanes
std::vector<InitialPlaneData> readFromFile()
{

	std::ifstream infile;
	infile.open("input.txt");

	std::vector<InitialPlaneData> initialPlanes;
	
	
	std::string line;

	while (std::getline(infile, line))
	{
		std::string current = "";

		std::vector<int> data;
		for (int i = 0; i < line.length(); i++)
		{
			if (line.at(i) == ' ')       //if current char is delimiter, then...
			{
				if (current.length() > 0)
				{
					data.push_back(std::stoi(current)); // then push every saved character/string before the delimiter into element of the vector, also convert the string to int before so.
					current = "";                       // resets the saved caracter back to empty string
				}
			}
			else
			{
				current += line.at(i); //if current char on line is not delimiter, save every character up till now, which forms a string
			}
			
			
		}

		data.push_back(std::stoi(current));         
		
		InitialPlaneData singlePlane(data);     // call constructor for a single Initial Plane
		
		initialPlanes.push_back(singlePlane); // push that constructed Initial Plane into the vector of Initial Planes

	}
	
	
	
	infile.close();

	return initialPlanes;
}

