#include <iostream>

#include "tools.h"
#include "Sort.h"

using namespace std;
int main()
{
    vector<int> v{3,5,-1,20,-8,3,10};
    insertSort(v);
    for(auto i : v)
        cout << i << endl;
    return 0;
}
