//
//  red-black-tree.hpp
//  Data-Structure
//
//  Created by Eddy Chu on 2021/2/24.
//

#ifndef red_black_tree_hpp
#define red_black_tree_hpp

#include <stdio.h>

enum class Color {RED, BLACK};

struct Node
{
    int data;
    Node *left, *right, *parent;
    Color color;
    Node (int data);
};

class RBTree
{
private:
    Node *root;
protected:
    void rotateLeft(Node *&, Node *&); //note: we pass root as argument to make sure RBTree is updated after the operation
    void rotateRight(Node *&, Node *&);
    void fixViolation(Node *&, Node *&);
public:
    RBTree();
    void insert(int);
    void inOrder();
    void levelOrder();
};


#endif /* red_black_tree_hpp */
