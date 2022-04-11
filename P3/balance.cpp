#include "node.h"

// your includes here
#include <cmath> //needed for abs()
#include <iostream>
#include <vector>
void traverseLoop(node* root, int &weight)
{
    if(root->left != NULL)
    {
        weight++;
        traverseLoop(root->left, weight);
    }
    if(root->right != NULL)
    {
        weight++;
        traverseLoop(root->right,weight);
    }
}
bool isWeightBalanced(node* root, int k) { 

    
	// your implementation here
    
    int leftWeight = 0, rightWeight = 0;
    bool lResult = true;
    bool rResult = true;
    node* traverse = root;
    if((traverse->left) != NULL)
    {
        leftWeight++;
        traverseLoop(traverse->left,leftWeight);
    }
    if(traverse->right != NULL)
    {
        rightWeight++;
        traverseLoop(traverse->right,rightWeight);
    }




    // if((root->left) != NULL)
    // {
    //     leftWeight++;
    //     lResult = isWeightBalanced(root->left, k);
    // }
    // if((root->right) != NULL)
    // {
    //     rightWeight++;
    //     rResult = isWeightBalanced(root->right,k);
    // }
    
    int difference = abs(leftWeight - rightWeight);
    if(difference > k) return false;
    // else if(!lResult || !rResult && k != 0) return false;
    else return true; // don't forget to upate this
}

// your helper methods here
// int main()
// {
//     node* root = new node(1);
//     root->left = new node(2);
//     root->right = new node(3);
//     root->right->left = new node(4);
//     root->right->left->left = new node(7);

//     root->right->left = new node(5);
//     root->right->right = new node(6);

//     bool result = isWeightBalanced(root, 1);
//     std::cout << result << std::endl;
//     return 0;
// }