#include "sorta.h"
#include <vector>

//#include <iostream> //used for print debugging
void sortLetters(std::string &input, std::vector<int> &counts)
{
    int i, j,num;
    char key;
    for (i = 1; i < counts.size(); i++)
    {
        key = input[i];
        num = counts[i];
        j = i - 1;
        while (j >= 0 && counts[j] > num)
        {
            input[j + 1] = input[j];
            counts[j+1] = counts[j];
            j--;
        }
        input[j + 1] = key;
        counts[j+1] = num;
    }
    
}
void sortAlpha(std::string &input, std::vector<int> &counts)
{
    // int("e") > int("r") > int("s")
    char temp;
    for(int i = 0; i < counts.size(); i++)
    {   
        if(counts[i] == counts[i+1] && input[i] > input[i+1])
        {
            temp = input[i];
            input[i] = input[i+1];
            input[i+1] = temp;
            i = -1;
            continue;
            
        }
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
    // std::cout << letters << std::endl;
    // for(int i = 0; i < counts.size(); i++)
    // {
    //     std::cout << letters[i] << ": " << counts[i] << std::endl;
    // }
    sortLetters(letters,counts);
    sortAlpha(letters,counts);
    for(int i = 0; i < letters.size(); i++)
    {
        while(counts[i] > 0)
        {
            output.push_back(letters[i]);
            counts[i]--;
        }
    }
    return output; // you will need to change this
}

// int main()
// {
//     std::string input = "engineering";
//     //std::cout << int("s") << " " << int("r") << std::endl;
//     std::cout << sortByFreq(input) << std::endl;
//     return 0;
// }