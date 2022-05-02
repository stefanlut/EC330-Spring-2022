#include "river.h"
#include <algorithm> // you are allowed to use std::sort from this library
// add your includes here
using std::sort;
// part (a)
void dfs(river const&r, int start,const int& end, std::vector<std::pair<int,bool>>& visited)
{

	for(int i = 0; i < end + 1; i++)
	{
		if(r[start][i] == 1 && (!visited[i].second))
		{
			visited.push_back(std::pair<int,bool>(i,1));
			dfs(r,i,end,visited);
		}
	}
}
std::vector<int> start(river const&r, int t) {

	// your implementation here
	std::vector<int> start_points = {};
	std::vector<std::pair<int,bool>> visited;
	visited.push_back(std::pair<int,bool>(0,0));
	for(int i = 0; i < t; i++)
	{
		dfs(r,i,t,visited);
	}
	
	for(auto iter = visited.begin(); iter != visited.end(); iter++)
	{
		if(!iter->second) start_points.push_back(iter->first);
		
	}
	for(int i = 1; i < t; i++)
	{
		for(auto iter = visited.begin(); iter != visited.end(); iter++)
		{
			if(iter->first == i) continue;
			else
			{
				start_points.push_back(i);
				break;
			} 
		
		}
	}
	sort(start_points.begin(),start_points.end());
	return start_points; // don't forget to change this
}

// part (b)
std::vector<int> meet(river const&r, int ryan, int mira) {

	// your implementation here

	return {}; // don't forget to change this
}