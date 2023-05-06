#include "./include/containers/map.hpp"
#include "./include/containers/stack.hpp"
#include "./include/lists/DBLinkList.hpp"
#include "./include/lists/LinkList.hpp"
#include "./include/trees/AVLTree.hpp"
#include "./include/trees/BSTree.hpp"
#include <iostream>
#include <map>

using namespace ADS;

int main(void) {
    try {
        Stack<int> st;
        st.push(12);
        st.push(14);
        std::cout<<st.top();
        st.pop();
        st.showElements();
    } catch (std::out_of_range& st) {
        std::cerr << st.what() << '\n';
    } catch (...) {
        std::cerr << "Catched exception ";
    }
    return 0;
}