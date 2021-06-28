#include <iostream>

using namespace std;

int calculate(int n, int m)
{
    if(n==m)
        return 1;
    
    int min = n>m?m:n;
    int max = n>m?n:m;

    int number = 1;
    int divider = 1;

    for(int i=1; i<=min; i++)
    {
        number *= (max-i+1);
        divider *= i;

        if(number%divider==0&&divider>1)
        {
            number/=divider;
            divider=1;
        }
    }

    return number;
}

int main(void)
{
    int n;

    cin>>n;

    for(int i=0; i<n; i++)
    {
        int n, m;

        cin>>n>>m;
        
        cout<<calculate(n,m)<<endl;
    }

    return 0;
}