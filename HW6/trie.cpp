#include <string>
#include "trie.h"

using namespace std;

void Trie::insert(string key, int val) {
    TrieNode* traverse = root;
    for(auto iter = key.begin(); iter != key.end(); iter++)
    {
        int index = *iter - 'a';
        if(!traverse->children[index])
        {
            traverse->children[index] = new TrieNode();
            this->tree_size++;
        }
        traverse = traverse->children[index];
        
    }
    traverse->val = val;
    this->map_size++;
}

int Trie::search(string key) {
    TrieNode* traverse = root;
    for(auto iter = key.begin(); iter != key.end(); iter++)
    {
        int index = *iter - 'a';
        if(!traverse->children[index])
        {
            return 0;
        }
        traverse = traverse->children[index];

    }
    return 1;
}

void Trie::remove(string key) {
    TrieNode* traverse = root;
    for(auto iter = key.begin(); iter != key.end(); iter++)
    {
        int index = *iter - 'a';
        traverse = traverse->children[index];
    }
    if(!traverse->children[*key.end()-1])
    {
        traverse = NULL;
        map_size--;
        tree_size--;
    }
    else
    {
        traverse->val = 0;
        map_size--;
    }
}
