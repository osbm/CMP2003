//Header File Binary Search Tree

#ifndef H_binarySearchTree
#define H_binarySearchTree
#include <iostream>
#include <cassert>
#include "binaryTree.h"

//*************************************************************
// Author: D.S. Malik
//
// This class specifies the basic operations to implement a
// binary search tree.
//*************************************************************

using namespace std;

template <class elemType>
class bSearchTreeType : public binaryTreeType<elemType>
{
public:
    bool search(const elemType& searchItem) const;
    //Function to determine if searchItem is in the binary 
    //search tree.
    //Postcondition: Returns true if searchItem is found in the 
    //    binary search tree; otherwise, returns false.

    void insert(const elemType& insertItem);
    //Function to insert insertItem in the binary search tree.
    //Postcondition: If no node in the binary search tree has the
    //    same info as insertItem, a node with the info insertItem
    //     is created and inserted in the binary search tree.

    void deleteNode(const elemType& deleteItem);
    //Function to delete deleteItem from the binary search tree 
    //Postcondition: If a node with the same info as deleteItem 
    //    is found, it is deleted from the binary search tree.

private:
    void deleteFromTree(binaryTreeNode<elemType>*& p);
    //Function to delete the node to which p points is deleted
    //from the binary search tree.
    //Postcondition: The node to which p points is deleted from
    //    the binary search tree.
};


template <class elemType>
bool bSearchTreeType<elemType>::
search(const elemType& searchItem) const
{
    binaryTreeNode<elemType>* current;
    bool found = false;

    if (this->root == NULL)
        cerr << "Cannot search the empty tree." << endl;
    else
    {
        current = this->root;

        while (current != NULL && !found)
        {
            if (current->info == searchItem)
                found = true;
            else if (current->info > searchItem)    //if searchItem smaller, continue search in the left subtree
                current = current->llink;
            else
                current = current->rlink;       //else, continue search in the right subtree
        }//end while
    }//end else

    return found;
}//end search

template <class elemType>
void bSearchTreeType<elemType>::insert(const elemType& insertItem)
{
    binaryTreeNode<elemType>* current;  //pointer to traverse the tree
    binaryTreeNode<elemType>* trailCurrent = NULL; //pointer behind current
    binaryTreeNode<elemType>* newNode;  //pointer to create the node

    newNode = new binaryTreeNode<elemType>;
    assert(newNode != NULL);
    newNode->info = insertItem;
    newNode->llink = NULL;
    newNode->rlink = NULL;

    if (this->root == NULL)
        this->root = newNode;
    else
    {
        current = this->root;

        while (current != NULL)
        {
            trailCurrent = current;

            if (current->info == insertItem)
            {
                cerr << "The insert item is already in the list-";
                cerr << "duplicates are not allowed: "
                    << insertItem << endl;
                return;
            }
            else if (current->info > insertItem)    //continue on left subtree
                current = current->llink;
            else
                current = current->rlink;           //continue on right subtree
        }//end while

        if (trailCurrent->info > insertItem)        //use trailCurrent to insert item
            trailCurrent->llink = newNode;
        else
            trailCurrent->rlink = newNode;
    }
}//end insert

template <class elemType>
void bSearchTreeType<elemType>::deleteNode(const elemType& deleteItem)
{
    binaryTreeNode<elemType>* current;  //pointer to traverse the tree
    binaryTreeNode<elemType>* trailCurrent; //pointer behind current
    bool found = false;

    if (this->root == NULL)
        cout << "Cannot delete from the empty tree." << endl;
    else
    {
        current = this->root;
        trailCurrent = this->root;

        while (current != NULL && !found)       //search for the deleteItem
        {
            if (current->info == deleteItem)
                found = true;
            else
            {
                trailCurrent = current;

                if (current->info > deleteItem)
                    current = current->llink;
                else
                    current = current->rlink;
            }
        }//end while

        if (current == NULL)
            cout << "The delete item is not in the tree." << endl;
        else if (found)
        {
            if (current == this->root)
                deleteFromTree(this->root);
            else if (trailCurrent->info > deleteItem)
                deleteFromTree(trailCurrent->llink);
            else
                deleteFromTree(trailCurrent->rlink);
        }//end if
    }
}//end deleteNode

template <class elemType>
void bSearchTreeType<elemType>::deleteFromTree
(binaryTreeNode<elemType>*& p)
{
    binaryTreeNode<elemType>* current; //pointer to traverse the tree
    binaryTreeNode<elemType>* trailCurrent;   //pointer behind current
    binaryTreeNode<elemType>* temp;        //pointer to delete the node

    if (p == NULL)
        cerr << "Error: The node to be deleted is NULL." << endl;
    else if (p->llink == NULL && p->rlink == NULL)  //Case 1: leaf
    {
        temp = p;
        p = NULL;
        delete temp;
    }
    else if (p->llink == NULL)  //Case 2: no left subtree
    {
        temp = p;
        p = temp->rlink;
        delete temp;
    }
    else if (p->rlink == NULL)  //Case 3: no right subtree
    {
        temp = p;
        p = temp->llink;
        delete temp;
    }
    else    //Case 4: nonempty left and right subtree (find predecessor of delete item)
    {
        current = p->llink;     //iterate to left child
        trailCurrent = NULL;

        while (current->rlink != NULL)      //continue on right subtree till the end
        {
            trailCurrent = current;
            current = current->rlink;       //at the end current shows the predecessor
        }//end while

        p->info = current->info;    //change p node info

        if (trailCurrent == NULL) //current did not move; 
                                  //current == p->llink; adjust p
            p->llink = current->llink;  //link adjustments for deletion
        else
            trailCurrent->rlink = current->llink;   //link adjustments for deletion

        delete current;
    }//end else
}//end deleteFromTree


#endif