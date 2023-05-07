#include "./include/containers/map.hpp"
#include "./include/containers/queue.hpp"
#include "./include/lists/DBLinkList.hpp"
#include "./include/lists/LinkList.hpp"
#include "./include/trees/AVLTree.hpp"
#include "./include/trees/BSTree.hpp"
#include "./include/containers/array.hpp"
#include <iostream>
#include <map>

using namespace ADS;

int main(void) {

    try {
        Array<int,5> arr{{10,20,30,40,50,60}};
        // + arr.fill(2);
        arr.showElements();
    } catch (std::out_of_range& st) {
        std::cerr << st.what() << '\n';
    } catch (...) {
        std::cerr << "Catched exception ";
    }
    return 0;
}