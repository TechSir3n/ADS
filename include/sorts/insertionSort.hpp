#ifndef ADS_INCLUDE_SORTS_INSERTIONSORT_HPP_
#define ADS_INCLUDE_SORTS_INSERTIONSORT_HPP_

#include <iostream>
#include <vector>

using namespace std;

void insertionSort(std::vector<int>& nums) { 
    for(std::size_t i = 1; i < nums.size();++i) { 
        int key = nums[i];
        int j = i - 1;

        while(j>=0 && nums[j]>key) { 
            nums[j+1] = nums[j];
            j = j -1;
        }
        nums[j+1] = key;
    }
}

#endif 