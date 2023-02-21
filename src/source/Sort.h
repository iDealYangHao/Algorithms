//
// Created by 杨昊 on 2023/2/20.
//

#ifndef SRC_SORT_H
#define SRC_SORT_H

#include <vector>

using std::vector;

template <typename eType>
void insertionSort(vector<eType> &vec)
{
    //只有一个或者没有没有元素时，该序列是自有序的
    if (vec.size() < 2)
        return;

    //每次for循环让有序队列长度加1
    for (int i = 1; i < vec.size(); ++i)
    {
        eType key = vec[i];
        int j = i - 1;

        //该条件保证了插入排序是个稳定的排序算法
        while (j >= 0 && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}

template <typename eType>
void selectionSort(vector<eType> &vec)
{
    //自有序
    if (vec.size() < 2)
        return;

    //循环n-1次，每次找到最小的元素和i位置的元素交换
    for (int i = 0; i < vec.size() - 1; ++i)
    {
        int minIndex = i;
        eType minElement = vec[i];

        //找到最小元素的下标
        for (int j = i + 1; j < vec.size(); ++j)
            if (vec[j] < minElement)  //该条件保证了选择排序的稳定性
            {
                minIndex = j;
                minElement = vec[j];
            }
        std::swap(vec[i], vec[minIndex]);
    }
}
#endif //SRC_SORT_H
