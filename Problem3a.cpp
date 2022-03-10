// your includes here
#include <vector>
#include <string>
#include <iostream>

// countOOO computes the number of pairs of elements in rankedListA that are out of order in rankedListB
int countOOO(std::vector<std::string> rankedListA, std::vector<std::string> rankedListB) {

	// your implementation goes here
	int count = 0;
	int numSongs = rankedListA.size();
	for(int i = 0; i < numSongs; i++)
	{
		for(int j = 0; j<numSongs;j++)
		{
			if(rankedListA[i] == rankedListB[j] && i != j) count++;
		}
	}
	return count; // don't forget to change this
}


int main()
{
	std::vector<std::string> rankedListA = {"E","G","S"};
	std::vector<std::string> rankedListB = {"S","E","G"};
	std::cout << countOOO(rankedListA,rankedListB) << '\n';
	return 0;
}