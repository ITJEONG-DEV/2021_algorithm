#include <iostream>

using namespace std;

int calculate(int a, int b)
{
    if(a%10==0)
        return 10;
        
    int n=1;
    for(int i=0; i<b; i++)
    {
        n = n*(a%10);

        if(n>10)
            n=n%10;
    }
    return n;
}

int main(void)
{
    int n;

    cin>>n;

    for(int i=0; i<n; i++)
    {
        int a, b;
        cin>>a>>b;

        cout<<calculate(a, b)<<endl;
    }
    return 0;
}