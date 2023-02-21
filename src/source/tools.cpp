//
// Created by 杨昊 on 2023/2/20.
//

#include "tools.h"

#include <vector>
#include <random>
#include <ctime>

//产生一个随机大小的vector，并且内部元素也是随机的
void generateVec(vector<int> &vec)
{
    //原始vec如有数据要清空
    vec.clear();

    //产生均匀分布的随机数
    std::default_random_engine e(time(0));
    std::uniform_int_distribution<int> size(0,100);
    std::uniform_int_distribution<int> element(-100, 100);

    int vecSize = size(e);
    for(int i = 0; i < vecSize; ++i)
        vec.push_back(element(e));
}