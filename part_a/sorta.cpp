#include "sorta.h"
#include <vector>

#include <iostream>
void sortLetters(std::string &input, std::vector<int> &counts)
{
    int i, j,num;
    char key;
    for (i = 1; i < input.size(); i++)
    {
        key = input[i];
        num = counts[i];
        j = i - 1;
        while (j >= 0 && input[j] > key)
        {
            input[j + 1] = input[j];
            counts[j+1] = counts[j];
            j = j - 1;
        }
        input[j + 1] = key;
        counts[j+1] = num;
    }
}
std::string sortByFreq(std::string s) {
	std::string output;
    std::vector<int> counts;
    std::string letters;
    int place = 0;
    for(int i = 0; i < s.size(); i++)
    {
        int letter_found = letters.find(s[i]);
        //if .find cannot find a substring, it will return string::npos
        if(letter_found == std::string::npos) 
        {
            
            letters.push_back(s[i]);
            counts.push_back(1);
            place++;
        }
        else
        {
            counts[letter_found]++;
        }
    }
    for(int i = letters.size()-1; i > -1; i--)
    {
        while(counts[i] > 0)
        {
            output.push_back(letters[i]);
        }
    }
    return output; // you will need to change this
}

int main()
{
    std::string input = "engineers";
    std::cout << sortByFreq(input) << std::endl;
    return 0;
}