//
// Created by 杨昊 on 2023/2/20.
//

#ifndef SRC_SORT_H
#define SRC_SORT_H

#include <vector>

using std::vector;
template <typename eType>
void insertSort(vector<eType> &vec)
{
    if (vec.size() < 2)
        return;

    for (int i = 1; i < vec.size(); ++i)
    {
        eType key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}
#endif //SRC_SORT_H
