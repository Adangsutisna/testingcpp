// Copyright (c) 2024 Nathan Greenfield. All rights reserved

#include "fileio.h"

#include <fstream>

bool getLineFromFile(const std::string& inputLocation, std::string& data)
{
	bool retval = false;
	
	// open the file
	std::ifstream inputFileContent(inputLocation);
	// check if opened successfully
	if(!inputFileContent.is_open())
	{
		return false;
	}
	//Reading the Contents
	if (!inputFileContent.eof())
	{
		std::getline(inputFileContent, data);
		retval=true;
	}
	//close the file
	inputFileContent.close();
	 return retval ;
}
