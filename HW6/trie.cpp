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
        if(traverse->children[index] == NULL)
        {
            return 0;
        }
        traverse = traverse->children[index];

    }
    if(traverse->val == 0 || traverse == NULL) return 0;
    return traverse->val;
}
void removal(Trie* tree, TrieNode* root, string key, int depth = 0)
{
    if(depth == key.size())
    {
        for(int i = 0; i < ALPHABET_SIZE; i++)
        {
            if(root->children[i]) break;
            
            delete root;
            root->val = 0;
            root = NULL;
            tree->tree_size--;
            tree->map_size--;
            return;
        }
        root->val = 0;
        tree->map_size--;;
        return;
    }
    int index = key[depth] - 'a';
    removal(tree,root->children[index],key, depth + 1);
    
    
    
}
void Trie::remove(string key) {

    removal(this, this->root,key,0);
    // TrieNode* traverse = root;
    // for(auto iter = key.begin(); iter != key.end(); iter++)
    // {
    //     int index = *iter - 'a';
    //     traverse = traverse->children[index];
    // }
    // if(!traverse->children[*key.end()-1])
    // {
    //     traverse = NULL;
    //     map_size--;
    //     tree_size--;
    // }
    // else
    // {
    //     traverse->val = 0;
    //     map_size--;
    // }
}
