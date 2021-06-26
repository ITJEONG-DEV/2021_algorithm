#include <iostream>

template <typename T>
inline T SQUARE(T x)
{
    return x*x;
}

using namespace std;

int value = 100;

int main(void)
{
    int num1 = 50;
    int *ptr = &num1;
    cout<<"num1: "<<num1<<endl;
    cout<<"ptr: "<<ptr<<endl;
    cout<<"*ptr: "<<*ptr<<endl;

    // cout<< SQUARE(5.5)<<endl;
    return 0;
}
