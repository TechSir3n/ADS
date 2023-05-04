#include "./include/lists/DBLinkList.hpp"
#include "./include/lists/LinkList.hpp"
#include "./include/trees/AVLTree.hpp"
#include "./include/trees/BSTree.hpp"
#include <iostream>

using namespace ADS;

int main(void) {

    BSTree<int> bst;
    bst.insertNode<BSTree<int>>(12);
    bst.insertNode<BSTree<int>>(19);
    bst.insertNode<BSTree<int>>(29);

    bst.erase<BSTree<int>>(19);
    // bst.printElements<BSTree<int>>();
    std::cout << '\n';

    AVLTree<int> avl;

    avl.insert<AVLTree<int>>(16);
    // avl.printElements<AVLTree<int>>();

    std::cout << '\n';

    LinkList<int> ls;
    ls.insert(102);
    ls.insert(107);
    ls.insert(155);

    // std::cout<<ls.getMinVal();
    std::cout << '\n';
    ls.erase(102);
    // ls.inorderPrint();

    DBLinkList<int> db_l;
    db_l.insert(10);
    db_l.insert(12);
    db_l.insert(16);

    db_l.erase(12);

    db_l.printElements();
    
    return 0;
}