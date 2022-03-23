#include <iostream>
#include <vector>
#include "bfilter.h"
#include <fstream>
int main() {
    
    BloomFilter bf = BloomFilter();
    // bf.insert("Hello, World!");
    // bf.insert("Lorem ipsum");

    // std::cout << (bf.member("foo bar") ?
    //         "'foo bar' is in our bloom filter" :
    //         "'foo bar' is not in our bloom filter")
    //     << std::endl;
    std::string line;
    std::ifstream myFile("phishing-links-ACTIVE.txt");
    if (myFile.is_open())
    {
        while ( getline (myFile,line) )
        {
            bf.insert(line);
        }
        myFile.close();
    } else std::cout << "Unable to open file";

    int count = 0;
    int count2 = 0;
    std::ifstream myFile2("phishing-links-INACTIVE.txt");
    if (myFile2.is_open())
    {
        while ( getline (myFile2,line) )
        {
            // cout<<line<<endl;
            if (bf.member(line)) {
                count2++;
            }
            count++;
        }
        myFile2.close();
    } else std::cout << "Unable to open file";

    std::cout << "Percentage of phishing links that are in the bloom filter: " << ((double)count2 / (double)count) * 100.0 << "%" << std::endl;

    return 0;
}
