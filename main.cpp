#include <vector>
#include "vector.hpp"
#include <iostream>
using namespace std;
int main()
{
    vector<int> a(5, 6);
    cout << a.capacity() << std::endl;
    cout << a.size() << std::endl;
}