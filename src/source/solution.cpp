//
// Created by 杨昊 on 2023/2/23.
//

#include "solution.h"
#include "Sort.cpp"

#include <vector>

bool existTwoNumber(const int s[], const int size, const int x)
{
    if (size < 2)
        return false;

    std::vector<int> vec(size);
    for (int i = 0; i < size; ++i)
        vec[i] = s[i];
    mergeSort(vec, 0, vec.size() - 1); //先排序，时间复杂度O(nlogn)

    //采用双指针法,时间上限为O(n)
    int left = 0, right = size -1;
    while (left < right)
    {
        if (vec[left] + vec[right] < x)
            ++left;
        else if (vec[left] + vec[right] > x)
            --right;
        else
            return true;
    }
    return false;
}
