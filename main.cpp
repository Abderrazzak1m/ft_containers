#include <vector>
#include "reverse_iterator.hpp"
#include "vector.hpp"
#include <iostream>
using namespace std;
int main()
{
    // ft::vector
    // vector<int> a;
    // int ar[] = {1, 2, 3};
//    ft::vector<int> d(5,12);
//    ft::vector<int>::iterator d(ar);
//    std::cout << *d << std::endl;
//    std::cout << *(d + 1) << std::endl;
//    std::cout << *(d + 2) << std::endl;
    // a.push_back(5);
    // a.push_back(7);
    // a.push_back(6);
    // a.push_back(8);
    // a.push_back(9);
    // vector<int>::iterator  c = a.begin();
    // vector<int>::iterator  v = a.end();
     ft::vector<std::string> h(6, "hello");
     h.reserve(6);
    //  ft::vector<int> d;
    //  h.resize(3);
    //  d = h;
     ft::vector<std::string>::iterator it = h.begin();
     while(it != h.end())
     {
        std::cout << *it << std::endl;
        it = it + 1;
     }
    //  std::cout<< h.size() << std::endl;
    
    cout << h.capacity() << std::endl;
    cout << h.size() << std::endl;
    // cout << a.size() << std::endl;
    // system("leaks ft_container");
}