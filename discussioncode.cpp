#include <cstdlib>
struct Node
{
    int data;
    Node* left;
    Node* right;
};

void insert(Node* root, int data)
{
    if(data < root->data)
    {
        if(root->left == nullptr)
        {
            Node* newNode = new Node;
            newNode->data = data;
        }
    }
    else
    {
        if(root->right == nullptr)
        {
            Node* newNode = new Node;
            newNode->data = data;
        }
    }
    
    
    return;
}

int main()
{
    Node* root = new Node;
    root->data = rand();
    int r;
    for(int i = 0; i < 100; i++)
    {
        r = rand();

    }
}