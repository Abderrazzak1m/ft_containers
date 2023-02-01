// Online C++ compiler to run C++ program online
#include <iostream>
#include <memory>
#include <string>

using namespace std;
class A {
    
    public:
        int a;
        A(int a = int())
        {
            cout << "contruct " << a << '\n';
        }
    
        ~A()
        {
            cout << "destruct\n";
        }
};

int main() {
    
    allocator<A> myAllocator;
 
    // allocate space for three strings
    A* str = myAllocator.allocate(1);
    
    myAllocator.construct(str);
    

    return 0;
}