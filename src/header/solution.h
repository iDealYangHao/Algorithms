//
// Created by 杨昊 on 2023/2/23.
//

#ifndef SRC_SOLUTION_H
#define SRC_SOLUTION_H

#include <vector>
using std::vector;
/*
 * 给定整型数组S[]和整数x，在O(nlgn)内找到S中是否存在两个数，
 * 使得s[i]+s[j] == x,且i != j
 */
bool existTwoNumber(const int s[], const int size, const int x);

/*
 * Let A[n] is an array of n distinct integers, find the number of inversions.
 *inversion means that A[i] > A[j] but i < j (Hint:modify merge sort)
 */
size_t countInversions(vector<int> &vec, size_t left, size_t right);
size_t mergeWithCount(vector<int> &vec, size_t left, size_t mid, size_t right);

#endif //SRC_SOLUTION_H
