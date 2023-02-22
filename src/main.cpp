#include <iostream>

#include "tools.h"
#include "Sort.cpp"

using namespace std;
int main()
{
    vector<int> v;
    generateVec(v);
    selectionSort(v);
    for(auto i : v)
        cout << i << '\t';
    return 0;
}
