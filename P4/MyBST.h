#ifndef __MYBST_H__
#define __MYBST_H__

#include "BST.h"

class MyBST : public BST
{
    using BST::BST;
    public:
        //MyBST();
        
        vector<Rotation> transform(MyBST target);
    private:
        Node* rotateRight(Node* Q);
        Node* rotateLeft(Node* P);
};

#endif /* __MYBST_H__*/