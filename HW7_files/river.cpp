#include "river.h"
#include <algorithm> // you are allowed to use std::sort from this library
// add your includes here

// part (a)
std::vector<int> start(river const&r, int t) {

	// your implementation here
	std::vector<int> start_points = {};
	for(int i = 0; i < t; i++)
	{
		start_points.push_back(i);
		
	}
	std::sort(start_points);
	return start_points; // don't forget to change this
}

// part (b)
std::vector<int> meet(river const&r, int ryan, int mira) {

	// your implementation here

	return {}; // don't forget to change this
}