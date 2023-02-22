#include <iostream>

#include "tools.h"
#include "Sort.cpp"

using namespace std;
int main()
{
    vector<int> v;
    generateVec(v);
    vector<int> b(v);

    insertionSort(v);
    for(auto i : v)
        cout << i << '\t';
    cout << endl;

    mergeSort(b, 0, b.size() - 1);
    for(auto i : v)
        cout << i << '\t';
    return 0;
}
