#include <iostream>

#include "tools.h"
#include "Sort.cpp"
#include "solution.h"

using namespace std;
int main()
{
    vector<int> v;
    generateVec(v);
    bubbleSort(v);
    for (auto i : v)
        cout << i << '\t';

    cout << countInversions(v, 0, v.size() - 1) << endl;
    return 0;
}
