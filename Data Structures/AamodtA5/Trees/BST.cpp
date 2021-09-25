#include <iostream>
#include <iomanip>
#include "BST.h"

using namespace std;

BST::BST() : root(NULL)
{
    root = nullptr;
}

BST::BST(const BST & existingBST)
{
    TNodePtr newNodePtr = existingBST.root;
    root = nullptr;
    copy(root);
}

void BST::copy(TNodePtr & nodePtr)
{
    if(nodePtr == nullptr)
        return;
    else
    {
        insert(nodePtr->key);
        copy(nodePtr->left);
        copy(nodePtr->right);
    }
}

BST::~BST()
{
    destroy(root);
}

void BST::destroy(TNodePtr & nodePtr)
{
    if(nodePtr)
    {
        if(nodePtr->left)
            destroy(nodePtr->left);
        if(nodePtr->right)
            destroy(nodePtr->right);
        delete nodePtr;
    }
}

void BST::preView() const
{
    cout << "Begin -> ";

    preView(root);

    cout << "End" << endl;
}

void BST::inView() const
{
    cout << "Begin -> ";

    inView(root);

    cout << "End" << endl;
}

void BST::postView() const
{
    cout << "Begin -> ";

    postView(root);

    cout << "End" << endl;
}

void BST::insert(const Key input)
{
    insert(input, root);
}

void BST::remove(const Key input)
{
    remove(input, root);
}

TNodePtr BST::search(const Key input) const
{
    return search(input, root);
}



//NON EXPORTABLE RECURSIVE VERSIONS OF EXPORTABLE FUNCTIONS
void BST::preView(const TNodePtr nodePtr) const
{
    if(nodePtr == nullptr)
    {
        return;
    }
    cout << nodePtr->key << " -> ";
    preView(nodePtr->left);
    preView(nodePtr->right);
}

void BST::inView(const TNodePtr nodePtr) const
{
    if(nodePtr == nullptr)
    {
        return;
    }
    inView(nodePtr->left);
    cout << nodePtr->key << " -> ";
    inView(nodePtr->right);
}

void BST::postView(const TNodePtr nodePtr) const
{
    if(nodePtr == nullptr)
    {
        return;
    }
    postView(nodePtr->left);
    postView(nodePtr->right);
    cout << nodePtr->key << " -> ";
}

void BST::insert(const Key input, TNodePtr & nodePtr)
{
    if(nodePtr == nullptr)
    {
        nodePtr = new (std::nothrow) TNode;
        nodePtr->key = input;
        nodePtr->left = nullptr;
        nodePtr->right = nullptr;
    }
    else if(input < nodePtr->key)
        insert(input, nodePtr->left);
    else if(input > nodePtr->key)
        insert(input, nodePtr->right);
}

void BST::remove(const Key input, TNodePtr & nodePtr)
{
    if (nodePtr == nullptr)
    {
        cout << "Key not found!" << endl;
    }
    else if(nodePtr->key == input)
    {
        removeNode(nodePtr);
    }
    else if(nodePtr->key > input)
    {
        remove(input, nodePtr->left);
    }
    else
    {
        remove(input, nodePtr->right);
    }
}

void BST::removeNode(TNodePtr & nodePtr)
{
    TNodePtr tempNodePtr = nullptr;

    if(nodePtr->left == nullptr && nodePtr->right == nullptr)
    {
        nodePtr = nullptr;
        delete nodePtr;
    }
    else if(nodePtr->left && !nodePtr->right)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;
        delete tempNodePtr;
    }
    else if(nodePtr->right && !nodePtr->left)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
    else
    {
        findMinNode(nodePtr->right, tempNodePtr);
        nodePtr->key = tempNodePtr->key;
        tempNodePtr = nullptr;
        delete tempNodePtr;
    }
}

void BST::findMinNode(TNodePtr & nodePtr, TNodePtr & temp)
{
    if(!nodePtr->left)
    {
        temp = nodePtr;
        nodePtr = nodePtr->right;
        return;
    }
    else
    {
        findMinNode(nodePtr->left, temp);
    }
}

TNodePtr BST::search(const Key input, TNodePtr nodePtr) const
{
    if (nodePtr == nullptr)
    {
        cout << "Key not found!" << endl;
        return nullptr;
    }
    else if(nodePtr->key == input)
        return nodePtr;
    else if(nodePtr->key > input)
    {
        return search(input, nodePtr->left);
    }
    else
    {
        return search(input, nodePtr->right);
    }
}
