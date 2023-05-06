#include "./include/containers/map.hpp"
#include "./include/lists/DBLinkList.hpp"
#include "./include/lists/LinkList.hpp"
#include "./include/trees/AVLTree.hpp"
#include "./include/trees/BSTree.hpp"
#include <iostream>
#include <map>

using namespace ADS;

int main(void) {
    Map<int, int> mp_t1;
    mp_t1.insert(std::pair<int, int>(10, 20));
    mp_t1.insert(std::pair<int, int>(30, 40));
    mp_t1.erase(30);
    mp_t1.printData();
    
    return 0;
}