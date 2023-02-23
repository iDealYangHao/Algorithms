//
// Created by 杨昊 on 2023/2/20.
//

#ifndef SRC_SORT_CPP
#define SRC_SORT_CPP

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

//归并排序工具函数，执行将两个有序队列合成一个有序队列的操作
//左区间为[left,mid],右区间为[mid+1,right]
template <typename eType>
void merge(vector<eType> &vec, int left, int mid, int right)
{
    //将左区间元素暂存到另一个vector中
    int leftLength = mid - left + 1;
    vector<eType> subVec(leftLength);
    for (int i =0; i < leftLength; ++i)
        subVec[i] = vec[left + i];

    int leftIndex = 0, rightIndex = mid + 1;
    for (int i = left; i <= right; ++i)
    {
        //两种情况可以选择左边的元素
        if (leftIndex<leftLength && (rightIndex > right || subVec[leftIndex] <= vec[rightIndex]))
            vec[i] = subVec[leftIndex++];
        else  //不检查rightIndex是因为for循环隐式地保证了它的合法访问
            vec[i] = vec[rightIndex++];
    }
}
template <typename eType>
void mergeSort(vector<eType> &vec, int left, int right)
{
    //区间长度小于等于1时，自有序,递归开始返回
    if (right - left < 1)
        return;

    int midIndex = (left + right) / 2;  //将区间一分为二
    //递归地使左右区间分别有序
    mergeSort(vec, left, midIndex);
    mergeSort(vec, midIndex + 1, right);

    //将有序的左右区间合成一个大区间
    merge(vec, left, midIndex, right);
}

//插入排序递归版的工具函数，将A[n]插入到已经有序的A[0...n-1]中
template <typename eType>
void insert(vector<eType> &vec, int index)
{
    int i = index - 1;
    eType key = vec[index];
    while (i >=0 && vec[i] > key)
    {
        vec[i + 1] = vec[i];
        --i;
    }
    vec[i + 1] = key;
}

template <typename eType>
void insertionSort_recursive(vector<eType> &vec, int index)
{
    //递归基
    if (index < 1)
        return;

    insertionSort_recursive(vec, index - 1);//递归使A[0...n-1]有序
    insert(vec, index);//将A[n]插入有序的A[0...n-1]，使有序序列扩大到A[0...n]
}

template <typename eType>
void bubbleSort(vector<eType> &vec)
{
    if (vec.size() < 2)
        return;

    bool isSorted = false;  //可以提前退出的标志变量
    size_t unsortedLength = vec.size();
    while (!isSorted)
    {
        isSorted = true;
        //i从1开始，比较vec[i-1]和vec[i],可以保证访问的元素不越界，
        for (int i = 1; i < unsortedLength; ++i)
            if (vec[i - 1] > vec[i])  //此条件保证了冒泡排序的稳定性
            {
                std::swap(vec[i - 1], vec[i]);
                isSorted = false;
            }
        --unsortedLength;
    }
}
#endif //SRC_SORT_CPP
