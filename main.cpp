#include <iostream>
#include "./include/BSTree.hpp"

int main(void) {
    TreeNode<int> *node = new TreeNode<int>(10);
    BSTree<int> bst;

    bst.insert(15, node);
    bst.insert(23, node);
    bst.insert(12, node);
    bst.insert(22, node);
    bst.erase(15,node);
    
    node->preorderPrint(node);
    std::cout << '\n';
    
    // node->postorderPrint(node);

    // std::cout << '\n';
    // node->reversePrint(node);

    // std::cout<<node->CountNodes(node);

    return 0;
}