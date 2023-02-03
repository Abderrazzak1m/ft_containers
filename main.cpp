#include <vector>
#include "vector.hpp"
#include <iostream>
using namespace std;
int main()
{
    vector<int> a;
    a.push_back(5);
    a.push_back(7);
    a.push_back(6);
    a.push_back(8);
    a.push_back(9);
    vector<int>::iterator  c = a.begin();
    vector<int>::iterator  v = a.end();
     ft::ft_vector<int> h(c, v);
    ft::ft_vector<float> d(5, 6);
    // cout << a.capacity() << std::endl;
    // cout << a.size() << std::endl;
}