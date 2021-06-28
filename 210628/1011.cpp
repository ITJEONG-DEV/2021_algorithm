#include <iostream>
#include <cmath>

using namespace std;

int swap(unsigned int x, unsigned int y)
{
    unsigned int term = y-x;

    unsigned int num = sqrt(term);

    while(1)
    {
        unsigned int odd = num*num;
        unsigned int even = num*(num+1);

        if(term<=odd)
            return (num-1)*2+1;
        else if(odd<term&&term<=even)
            return num*2;
        else num+=1;
    }
}
int main(void)
{
    int n;

    cin>>n;

    unsigned int x, y;
    for(int i=0; i<n; i++)
    {
        cin>>x>>y;
        cout<<swap(x, y)<<endl;
    }

    return 0;
}