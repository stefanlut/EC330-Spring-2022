#include "river.h"
#include <algorithm> // you are allowed to use std::sort from this library
// add your includes here
using std::sort;
// part (a)
void dfs(river const&r, int start,int end, std::vector<std::pair<int,bool>>& visited)
{

	for(int i = 0; i < end; i++)
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
	dfs(r,0,t,visited);
	for(auto iter = visited.begin(); iter != visited.end(); iter++)
	{
		if(!iter->second) start_points.push_back(iter->first);
	}
	sort(start_points.begin(),start_points.end());
	return start_points; // don't forget to change this
}

// part (b)
std::vector<int> meet(river const&r, int ryan, int mira) {

	// your implementation here

	return {}; // don't forget to change this
}