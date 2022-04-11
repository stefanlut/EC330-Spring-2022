#include <vector>
#include "bfilter.h"
#include <iostream>
// (a)

class SillyHashFun : public HashFun {
    unsigned int operator()(const std::string& key) {
        // Here's my silly hash function that always returns 0.
        // You should make some good hash functions and not use this one.
        // This is just an example of how to inherit the HashFun class.
        return 0;
    }
};

//Using hash functions from http://www.partow.net/programming/hashfunctions/index.html#top

class GoodHashFun_0 : public HashFun {
    unsigned int operator()(const std::string& key) {
    unsigned int hash = 0;
    unsigned int i    = 0;

   for (i = 0; i < key.length(); ++i)
   {
      hash = key[i] + (hash << 6) + (hash << 16) - hash;
   }

   return hash; // You'll need to change this
    }
};

// Adding two more Hash Functions
// From same website as above, 04 - BKDR Hash Function
class GoodHashFun_1 : public HashFun{
    unsigned int operator()(const std::string& key)
    {
        unsigned int seed = 131; /* 31 131 1313 13131 131313 etc.. */
        unsigned int hash = 0;
        unsigned int i    = 0;

        for (i = 0; i < key.length(); ++i)
        {
            hash = (hash * seed) + key[i];
        }

        return hash;
    }
};
class GoodHashFun_2 : public HashFun{
    unsigned int operator()(const std::string& key)
    {
        unsigned int hash = 0;
        unsigned int x    = 0;
        unsigned int i    = 0;

        for (i = 0; i < key.length(); ++i)
        {
            hash = (hash << 4) + key[i];

            if ((x = hash & 0xF0000000L) != 0)
            {
                hash ^= (x >> 24);
            }

            hash &= ~x;
        }

   return hash;
    }
};
class GoodHashFun_3 : public HashFun{
    unsigned int operator()(const std::string& key)
    {
        unsigned int hash = 5381;
        unsigned int i    = 0;

        for (i = 0; i < key.length();  ++i)
        {
            hash = ((hash << 5) + hash) + key[i];
        }
        return hash;
    }
};
void BloomFilter::add_hash_funs() {
    // You will need to implement this function, it is responsible
    // for adding your custom hash functions to your bloom filter.

    // Here's an example where I add two hash functions.
    // You will need to add at least one hash function.
    
    //this->hash_funs.push_back(new GoodHashFun_0());
    //this->hash_funs.push_back(new GoodHashFun_1());
    this->hash_funs.push_back(new GoodHashFun_2()); // Best performance so far
    //this->hash_funs.push_back(new GoodHashFun_3()); 
    // GoodHashFun_0 *h1 = new GoodHashFun_0();
    // GoodHashFun_1 *h2 = new GoodHashFun_1();
    // GoodHashFun_2 *h3 = new GoodHashFun_2();
    // this->hash_funs.push_back(h1);
    // this->hash_funs.push_back(h2);
    // this->hash_funs.push_back(h3);
}

void BloomFilter::insert(const std::string& key) {
    // You will need to implement this function, it is responsible
    // for inserting key into the bloom filter.
    for(int i = 0; i < this->hash_funs.size(); i++)
    {
        (this->filter)[this->call_hash(i,key) % 330] = 1;
    }
    // Here's how you can call your hash functions that you added in add_hash_funs()
    //unsigned int first_hash_result = this->call_hash(0, key);
    //std::cout << "Hash of '" << key << "' is '" << first_hash_result << "' using the first hash function." << std::endl;
    //unsigned int second_hash_result = this->call_hash(1, key);
    //std::cout << "Hash of '" << key << "' is '" << second_hash_result << "' using the second hash function." << std::endl;
    //unsigned int third_hash_result = this->call_hash(2,key);
    // You'll need to use the results of the hash function to update this->filter
    // Here's an example
    // (this->filter)[first_hash_result % 330] = 1;
    // (this->filter)[second_hash_result % 330] = 1;
    // (this->filter)[third_hash_result % 330] = 1;
    
}

bool BloomFilter::member(const std::string& key) {
    // This function should report true if key is potentially in the bloom filter.
    // It should only return false if you know for sure that key is not in the bloom filter.
    bool check = false;
    //
    // your code here ...
    for(int i = 0; i < hash_funs.size(); i++)
    {
        if( (this->filter)[this->call_hash(i,key) % 330] == 1 ) return true;
    }
    //
    
    return check; // you will need to change this.
}
