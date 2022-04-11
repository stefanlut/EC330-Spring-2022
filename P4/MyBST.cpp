//
//  MyBST.cpp
//  bst_transform
//
#include <iostream>
#include "MyBST.h"

using namespace std;

/**
 * Computes how to transform this MyBST into the target MyBST using rotations.
 * Returns a vector of rotations indicating which rotations around which nodes
 * must be performed to transform this into the target.
 *
 * IMPORTANT: We want to transform T1 into T2 so the call should look like
 * rotations = t1.transform(t2)
 */

void recursiveRotate(Node* parent, Node* target, vector<Rotation>& transformList)
{
    //BASE CASES
    if(parent->right->key == target->key) //rotate child and parent to the left
    {
        Rotation* one = new Rotation(parent->right->key, ZAG);
        Rotation* two = new Rotation(parent->key,ZAG);
        transformList.push_back(*one);
        transformList.push_back(*two);
    }
    else if(parent->left->key == target->key) //rotate child and parent to the right
    {
        Rotation* one = new Rotation(parent->left->key, ZIG);
        Rotation* two = new Rotation(parent->key,ZIG);
        transformList.push_back(*one);
        transformList.push_back(*two);
    }
    else if(parent->key < target->key && parent->right != NULL)
    {
        recursiveRotate(parent->right,target,transformList);
    }
    else if(parent->key > target->key && parent->left != NULL)
    {
        recursiveRotate(parent->left,target,transformList);
    }
}

vector<Rotation> MyBST::transform(MyBST target) {
  /*** Your implementation should go here. ***/
    vector<Rotation> transformList;
    Node* traverse = this->root;
    Node* parent = this->root;      // follow the traverse pointer
    bool if_rotate = false;         // tell me when a rotation occured
    
    if (traverse == NULL && target.root == NULL) return {};

    while (this->root->key != target.root->key) {     // until target root is at this->root
        if (traverse->key < target.root->key) {
            if (traverse->right->key != target.root->key) {
                parent = traverse;
                traverse = traverse->right;
            }
            else {
                // it found the key to the right of traverse -> left rotate
                Rotation* one = new Rotation(traverse->key,ZAG);
                transformList.push_back(*one);
                if (traverse == this->root) {           // if it works, do this to ZIG as well
                    this->root = rotateLeft(traverse);
                }
                else {
                    if (parent->left == traverse){
                        parent->left = rotateLeft(traverse);    // how to tell if it should be left or right?
                    }
                    else if (parent->right == traverse) {
                        parent->right = rotateLeft(traverse);
                    }
                }
                if_rotate = true;
            }
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////
        else if (traverse->key > target.root->key) {
            if (traverse->left->key != target.root->key) {
                parent = traverse;
                traverse = traverse->left;
            }
            else {
                // found the key to the left of traverse -> right rotate
                Rotation* one = new Rotation(traverse->key,ZIG);
                transformList.push_back(*one);
                if (traverse == this->root) {
                    this->root = rotateRight(traverse);
                }
                else {
                    if (parent->left == traverse){
                        parent->left = rotateRight(traverse);
                    }
                    else if (parent->right == traverse) {
                        parent->right = rotateRight(traverse);
                    }
                }
                if_rotate = true;
            }
        }
        if (if_rotate) {
            traverse = this->root;      // after each rotation, move traverse pointer back to top of BST
            parent = this->root;
            if_rotate = false;
        }
    }
    return transformList;
    	
}

// You can use the rotation functions below as a starting point, 
// or you can choose your own implementation strategy.

// I think these rotate functions don't take into account nodes with 2 children. Check and if it doesn't work,
// update it to make it work properly for nodes with two children as well.
Node* MyBST::rotateRight(Node* Q)
{
    Node* P = Q->left;
    Q->left = P->right;
    P->right = Q;
    return P;
}

Node* MyBST::rotateLeft(Node* P)
{
    Node* Q = P->right;
    P->right = Q->left;
    Q->left = P;
    return Q;
}