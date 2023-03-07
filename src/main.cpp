#include <iostream>

#include "tools.h"
#include "Sort.cpp"
#include "solution.h"

using namespace std;
int main()
{
    vector<int> v{13 ,-3,-25, 20, -3,-16,-23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    auto t = findMaxSubarray(v, 0, v.size() - 1);
    cout << get<2>(t) << endl;
    return 0;
}
