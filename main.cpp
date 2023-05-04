#include <iostream>

#include "./include/containers/map.hpp"
#include "./include/lists/DBLinkList.hpp"
#include "./include/lists/LinkList.hpp"
#include "./include/trees/AVLTree.hpp"
#include "./include/trees/BSTree.hpp"

using namespace ADS;

int main(void) {
    AVLTree<int> st;
    Map<int, int> mp;
    mp.insert(std::make_pair(10, 20)); // need to do some bag
    st.printElements();

    return 0;
}