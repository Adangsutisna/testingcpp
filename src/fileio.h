// Copyright (c) 2024 Nathan Greenfield. All rights reserved
#pragma once

#include <string>

// Name: 
//		getLineFromFile
// Input:
//		1. A string (passed as constant reference) containing the input file name
//		2. A string (passed by reference) that will eventually contain the first line of the file
// Output: 
//		boolean -- true indicating success
// Side effects: 
//		Reads the input file
// Summary:
//		Reads in the first line of a text file and copies data into the string
bool getLineFromFile(const std::string& inputLocation, std::string& data);