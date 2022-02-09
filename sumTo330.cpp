
#include <vector>
#include <cmath>
#include <algorithm>
using std::vector;
using std::sort;
int sumTo330(vector<int> nums) {
	int result;
	
	sort(nums.begin(),nums.end());

	for(auto iter1 = nums.begin(); iter1 != nums.end(); iter1++)
	{
		auto itery = iter1 + 1;
		auto iterz = nums.end() - 1;
		while(iterz > itery)
		{
			int sum = *iter1 + *itery + *iterz;
			if(sum == 330) return sum;
			if(abs(330-sum) < abs(330-result))
			{
				result = sum;
				
			} 
			else if(abs(330-sum) == abs(330-result)) result = (sum < result) ? sum : result;
			
			iterz--;

		} 
	}

	return result; 
}

