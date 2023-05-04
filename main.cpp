#include <map>

#include "./include/containers/map.hpp"
#include "./include/trees/AVLTree.hpp"

using namespace ADS;

int main(void) {
  AVLTree<int> st;
  Map<int, int> mp;
  mp.insert(std::make_pair(10, 20)); // need to do some bag 
  st.printElements();

  return 0;
}
