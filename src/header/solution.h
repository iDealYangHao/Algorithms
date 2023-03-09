//
// Created by 杨昊 on 2023/2/23.
//

#ifndef SRC_SOLUTION_H
#define SRC_SOLUTION_H

#include <vector>
#include <tuple>

using std::vector;
using std::tuple;
using std::get;

typedef tuple<size_t, size_t, int> subarray;
/*
 * 给定整型数组S[]和整数x，在O(nlgn)内找到S中是否存在两个数，
 * 使得s[i]+s[j] == x,且i != j
 */
bool existTwoNumber(int s[], int size, int x);

/*
 * Let A[n] is an array of n distinct integers, find the number of inversions.
 *inversion means that A[i] > A[j] but i < j (Hint:modify merge sort)
 */
size_t countInversions(vector<int> &vec, size_t left, size_t right);
size_t mergeWithCount(vector<int> &vec, size_t left, size_t mid, size_t right);

/*
 * Find the maximum subarray in A[n],such as:
 *{13 –3–25 20 –3– 16–23 18 20 –7 12 –5 –22 15 –4 7}
 *--------------------->|18 20 -7 12|<--------------sum is 43
 * any other subarray sum less than it.
 * T(n) = O(nlogn)
 */
subarray findMaxSubarrayDivideConquer(const vector<int> &vec, size_t low, size_t high);
subarray findCrossingMaxSubarray(const vector<int> &vec, size_t low, size_t mid, size_t high);

/*
 * Find the maximum subarray in A[n] within O(n),called Kadane's algorithm
 */
subarray findMaxSubarrayKadane(const vector<int> &vec, int low, int high);

/*
 * Find the maximum subarray in A[n] within O(n),using dynamic programming
 */
int findMaxSubarrayDP(const vector<int> &vec);
#endif //SRC_SOLUTION_H
