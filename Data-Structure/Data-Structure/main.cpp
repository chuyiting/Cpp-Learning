//
//  main.cpp
//  Data-Structure
//
//  Created by Eddy Chu on 2021/2/24.
//

#include <iostream>
#include "red-black-tree.hpp"

int main(int argc, const char * argv[]) {
    RBTree tree;
    tree.insert(7);
    tree.insert(6);
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);
  
    std::cout << "Inoder Traversal of Created Tree\n";
    tree.inOrder();
    
    std::cout << "\nLevel Order Traversal of Created Tree\n";
    tree.levelOrder();
    return 0;
}
