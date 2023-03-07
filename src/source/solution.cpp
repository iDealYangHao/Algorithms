//
// Created by 杨昊 on 2023/2/23.
//

#include "solution.h"
#include "Sort.cpp"

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

size_t countInversions(vector<int> &vec, size_t left, size_t right)
{
    //单个元素无逆序
    if (left == right)
        return 0;

    size_t count = 0;
    size_t midIndex = (left + right) / 2;

    //分别计算两个区间内部的逆序数
    count += countInversions(vec, left, midIndex);
    count += countInversions(vec, midIndex + 1, right);

    //然后计算两个区间之间的逆序数
    count += mergeWithCount(vec, left, midIndex, right);
    return count;
}

size_t mergeWithCount(vector<int> &vec, size_t left, size_t mid, size_t right)
{
    size_t count = 0;

    //复制前半段到新的vector中，以免在后续赋值时盖住了前半段数据
    size_t leftLength = mid - left + 1;
    vector<int> subVec(leftLength);
    for (size_t i = 0; i < leftLength; ++i)
        subVec[i] = vec[left + i];

    size_t leftPointer = 0, rightPointer = mid + 1;
    while (left <= right)
    {
        //左区间的数小于右区间的数，这是顺序
        if (leftPointer < leftLength && (rightPointer > right || subVec[leftPointer] <= vec[rightPointer]))
            vec[left++] = subVec[leftPointer++];
        else
        {
            /* 计算两个区间之间的逆序数方法核心，因其左右区间各自有序，则如下：
             * 左区：[3,5,8,9],右区：[2,6,7,10],因 2 < 3, 则2必然小于左区间里3及其之后数，逆序数加4，继续迭代
             * 左区：[8,9],右区:[6,7,10],因6 < 8,则6小于8和9，逆序数加2，继续迭代
             * 左区：[8,9],右区:[7,10],因7<8,则7小于8和9，逆序数加2，同理迭代...
             */
            if (leftPointer < leftLength)
                count += leftLength - leftPointer;
            vec[left++] = vec[rightPointer++];
        }
    }
    return count;
}

subarray findMaxSubarray(const vector<int> &vec, size_t low, size_t high)
{
    //base case:only one element
    if (low == high)
        return {low, high, vec[low]};

    //cut the array into two subarray,the maxSubarray may exist in leftSubarray or rightSubarray entirely,
    //otherwise, the maxSubarray crossing midpoint.
    size_t mid = (low + high) / 2;
    auto leftMaxSubarray = findMaxSubarray(vec, low, mid);
    auto rightMaxSubarray = findMaxSubarray(vec, mid + 1, high);
    auto crossingMaxSubarray = findCrossingMaxSubarray(vec, low, mid, high);

    //compare three number, return the max one
    int lMax = (int)get<2>(leftMaxSubarray), rMax = (int)get<2>(rightMaxSubarray), cMax = (int)get<2>(crossingMaxSubarray);
    if (lMax >= rMax && lMax >= cMax)
        return leftMaxSubarray;
    else if(rMax >= lMax && rMax >= cMax)
        return rightMaxSubarray;
    else
        return crossingMaxSubarray;
}

subarray findCrossingMaxSubarray(const vector<int> &vec, size_t low, size_t mid, size_t high)
{
    int leftMaxSum = INT_MIN;
    int sum = 0;
    size_t leftMaxIndex = mid;
    for (int i = (int)mid; i >= (int)low; --i)
    {
        sum += vec.at(i);
        if (sum > leftMaxSum)
        {
            leftMaxSum = sum;
            leftMaxIndex = i;
        }
    }

    sum = 0;
    size_t rightMaxIndex = mid + 1;
    int rightMaxSum = INT_MIN;
    for (int i = (int)mid + 1; i <= (int)high; ++i)
    {
        sum += vec.at(i);
        if (sum > rightMaxSum)
        {
            rightMaxSum = sum;
            rightMaxIndex = i;
        }
    }
    return {leftMaxIndex, rightMaxIndex, leftMaxSum + rightMaxSum};
}




