#include <iostream>

using namespace std;

int swap(int x, int y)
{
    int left = x+1;
    int right = y-1;

    int left_term = 1;
    int right_term = 1;

    while(left!=right)
    {

    }
}
int main(void)
{
    int n;

    cin>>n;

    int x, y;
    for(int i=0; i<n; i++)
    {
        cin>>x>>y;
        swap(x, y);
    }

    return 0;
}