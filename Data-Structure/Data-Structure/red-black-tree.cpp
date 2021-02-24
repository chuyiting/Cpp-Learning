//
//  red-black-tree.cpp
//  Data-Structure
//
//  Created by Eddy Chu on 2021/2/24.
//

/** C++ implementation for Red-Black Tree
 */

#include "red-black-tree.hpp"
#include <queue>
#include <iostream>


Node::Node (int data) {
    this->data = data;
    left = right = parent = nullptr;
    this->color = Color::RED;
}

void inOrderHelper(Node *toVisit)
{
    if (!toVisit)
    {
        return;
    }
    
    inOrderHelper(toVisit->left);
    std::cout << toVisit->data << "  ";
    inOrderHelper(toVisit->right);
}

void levelOrderHelper(Node *root) // equivalent of breadth first search
{
    std::queue<Node *> toVisit;
    toVisit.push(root);
    while (!toVisit.empty())
    {
        Node *curr = toVisit.front();
        toVisit.pop();
        std::cout << curr->data << "  ";
        
        if (curr->left)
            toVisit.push(curr->left);
        
        if (curr->right)
            toVisit.push(curr->right);
    }
    
}

bool isRightChild(Node* node)
{
    if (node->parent->right == node) {
        return true;
    }
    return false;
}

/**
 Assert uncle exists
 */
Node* getUncle(Node *node)
{
    if (isRightChild(node->parent))
    {
        return node->parent->parent->left;
    }
    
    return node->parent->parent->right;
}

RBTree::RBTree(){
    root = nullptr;
    
}

/**
 Assert: node and node-right are not null
 */
void RBTree::rotateLeft(Node *&root, Node *&node)
{
    Node *node_right = node->right;
    node->right = node_right->left;
    if (node->right)
        node->right->parent = node;
    
    if (!node->parent)
        root = node_right;
    else if (isRightChild(root))
        node->parent->right = node_right;
    else
        node->parent->left = node_right;
    
    node_right->left = node;
    node->parent = node_right;
}

/**
 Assert node and node->left are not nullptr
 */
void RBTree::rotateRight(Node *&root, Node *&node)
{
    Node *node_left = node->left;
    node->left = node_left->right;
    if (node->left)
        node->left->parent = node;
    
    if (!node->parent)
        root = node_left;
    else if (isRightChild(node))
        node->parent->right = node_left;
    else
        node->parent->left = node_left;
    node_left->right = node;
    node->parent = node_left;
}

void bstInsert(Node *&root, Node *node)
{
    if (!root)
    {
        root = node;
        return;
    }
    
    Node *toVisit = root;
    while (true)
    {
        if (node->data > toVisit->data && !(toVisit->right))
        {
            node->parent = toVisit;
            toVisit->right = node;
            break;
        }
        
        else if (node->data > toVisit->data)
        {
            toVisit->right = node;
            continue;
        }
        
        else if (node->data < toVisit->data && !(toVisit->left))
        {
            node->parent = toVisit;
            toVisit->left = node;
            break;
        }
        
        else if (node->data < toVisit->data)
        {
            toVisit = toVisit->left;
            continue;
        }
        
        else
        {
            break;
        }
    }
    
}

void RBTree::fixViolation(Node *&root, Node *&node)
{
    if (node == root)
    {
        node->color = Color::BLACK;
        return;
    }
    
    if (node->parent->color == Color::BLACK)
        return;
    
    Node* parent = node->parent;
    Node* uncle = getUncle(node);
    Node* grandParent = node->parent->parent; // this situation must have grandparent
    if (uncle && uncle->color == Color::RED)
    {
        uncle->color = Color::BLACK;
        node->parent->color = Color::BLACK;
        if (grandParent != root)
            grandParent->color = Color::RED;
    }
    
    else
    {
        if (isRightChild(node) && isRightChild(node->parent)) // right-right
        {
            rotateLeft(root, grandParent);
            parent->color = Color::BLACK;
            grandParent->color = Color::RED;
        }
        else if (!isRightChild(parent) && isRightChild(node)) // left-right
        {
            rotateLeft(root, parent);
            fixViolation(root, node); // go back to right-right
        }
        else if (!isRightChild(parent) && !isRightChild(node)) //left-left
        {
            rotateRight(root, grandParent);
            parent->color = Color::BLACK;
            grandParent->color = Color::RED;
        }
        else //right-left
        {
            rotateRight(root, parent);
            fixViolation(root, node); // go back to right-right
        }
    }
    
    
}

void RBTree::insert(int n)
{
    Node *node = new Node(n);
    bstInsert(root, node);
    fixViolation(root, node);
}


void RBTree::inOrder()
{
    inOrderHelper(root);
}

void RBTree::levelOrder()
{
    levelOrderHelper(root);
}

