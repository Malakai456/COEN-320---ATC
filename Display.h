#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

#include "Plane.h"
#include "ComputerSystem.h"



std::string vector_to_string(const std::vector<int>& v);

void updateDisplay(int time, std::vector<CurrentPlaneData> currentPlanes, std::vector<std::vector<int>> violations);