#include "job.h"
#include <vector>

using namespace std;

bool canFinish(int n, vector<pair<int, int>> &dependencies) { 
  bool conflict;
  for(int i = 0; i < n; i ++)
  {
    if(dependencies[i].first > dependencies[i].second) return false;
    
  }
  return true; 
  }

bool canRun(int n, vector<pair<int, int>> &dependencies, int j, int i) {
  return false;
}
