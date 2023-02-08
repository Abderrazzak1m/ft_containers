#include <vector>
#include <iostream>
#include <algorithm>

struct Point {
    int x;
    int y;
};

int main() {
    std::vector<Point> points;
    Point a;
    a.x = 1;
    a.y = 2;
    Point b;
    b.x = 3;
    b.y = 4;
    points.push_back(a);
    points.push_back(b);

    // Reverse iteration over the vector using reverse_iterator
    std::reverse_iterator<std::vector<Point>::iterator> rit = points.rbegin();
    
    std::cout << rit->x << " " << rit->y << std::endl;
    ++rit;
    std::cout << rit->x << " " << rit->y << std::endl;
    ++rit;
    std::cout << rit->x << " " << rit->y << std::endl;
    ++rit;

    return 0;
}