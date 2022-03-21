#include <cmath>
#include <algorithm>
#include <cstdlib>
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    int height;
    
    Node(int data):data(data){}
};

Node* insert( Node* n, int data)
{
    if(n == nullptr) return new Node(data);

    if(n->data > data)
    {
        n->left = insert(n->left,data);
    }
    else{
        n->right = insert(n->right,data);
    }
    n->height = max(n->left->height,n->right->height) + 1;
}