#pragma once

#include <string>
#include <vector>

// Name: 
//		strSplit
// Input:
//		1. A string (passed as constant reference) to split
//		2. A char delimiter containing the character to split on
// Output: 
//		Vector containing the parts of the string separated by the delimiter 
// Side effects: 
//		None
// Summary:
//		Given a string and a character to split on, returns a vector
//      of the split strings
std::vector<std::string> strSplit(const std::string& str, char splitChar);

