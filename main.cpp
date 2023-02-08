#include <vector>
#include "vector.hpp"
#include <iostream>
using namespace std;
// struct Point {
//     int x;
//     int y;
// };
int main()
{
    // std::vector<Point> points1;
    // Point a;
    // a.x = 1;
    // a.y = 2;
    // Point b;
    // b.x = 3;
    // b.y = 4;
    // points1.push_back(a);
    // points1.push_back(b);

    // ft::vector<Point> points(points1.begin(), points1.end());
    // // Reverse iteration over the vector using reverse_iterator
    // ft::vector<Point>::reverse_iterator rit = points.rbegin();
    // // ft::vector<Point>::reverse_iterator rit1 = points.rend();
    // std::cout << rit->x << " " << rit->y << std::endl;
    // ++rit;
    // std::cout << rit->x << " " << rit->y << std::endl;
    // ++rit;
    // std::cout << rit->x << " " << rit->y << std::endl;
    // ++rit;

    // return 0;
  // std::vector<int> myvector;
  // myvector.push_back(5);
  // myvector.push_back(4);
  // myvector.push_back(0);
  // myvector.push_back(12);
  // ft::vector<int> a(myvector.begin(), myvector.end());
  // ft::vector<int>::reverse_iterator it = a.rbegin();
  // ft::vector<int>::reverse_iterator cp(it);
  // std::cout<< *(it) << std::endl;
  // std::cout<< *(cp) << std::endl;
  // // it++;
  // // it++;
  // // it++;
  // // it++;
  // std::cout<< *(it - 1) << std::endl;
  // std::cout<< *(cp - 1) << std::endl;
    // ft::vector<int>::reverse_iterator it2 = a.rend();
    // std::vector<int>::reverse_iterator it1 = myvector.rend();
    
    // //   ft::vector<int>::iterator it  = *it2;
    // // it2--;
    // it2 -= 2;
    // it1 -= 2;
    // std::cout <<"for ft " << *(it2 )<<std::endl;
    // std::cout << "for std " <<*(it1 )<<std::endl;
    // it2++;
    // it1++;
  
    // std::cout <<"for ft " << *(it2 )<<std::endl;
    // std::cout << "for std " <<*(it1 )<<std::endl;
    // it2++;
    // it1++;
  
    // std::cout <<"for ft " << *(it2 )<<std::endl;
    // std::cout << "for std " <<*(it1 )<<std::endl;
    // it2++;
    // it1++;
  
    // std::cout <<"for ft " << *(it2 )<<std::endl;
    // std::cout << "for std " <<*(it1 )<<std::endl;
    // it2++;
    // it1++;
  
    // std::cout <<"for ft " << *(it2 )<<std::endl;
    // std::cout << "for std " <<*(it1 )<<std::endl;
//   while(it != a.end())
//   {
//     std::cout << *it <<std::endl;
//     it++;
//   }
ft::vector<int> a(6, 6);
ft::vector<int> b(a);
std::cout << b.capacity() << std::endl;
std::cout << b.size() << std::endl;


  // return 0;
}