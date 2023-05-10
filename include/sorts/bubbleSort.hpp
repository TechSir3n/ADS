#ifndef ADS_INCLUDE_SORTS_BUBBLESORT_HPP_
#define  ADS_INCLUDE_SORTS_BUBBLESORT_HPP_

#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(std::vector<int> &nums) { 
    for(std::size_t i =  0; i < nums.size() - 1; ++i) { 
        for(std::size_t j = 0; j < nums.size() - i - 1; ++j) { 
            if(nums[j] > nums[j+1]) { 
                swap(nums[j],nums[j+1]);
            }
        }
    }
}

#endif 