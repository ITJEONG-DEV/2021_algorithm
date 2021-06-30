#include <iostream>
#include <cmath>

using namespace std;

int get_price(int N, int M)
{
    int _6, _1;
    int __6 = 1001, __1= 1001;

    for(int i=0; i<M; i++)
    {
        cin>>_6>>_1;

        if(__6>_6)
            __6 = _6;
        
        if(__1>_1)
            __1 = _1;
    }

    if(__6 < __1*6)
    {
        int whole_6 = __6 * ceil((float)N/6);
        int max = __6 * int(N/6) + __1 * (N%6);

        return min(whole_6, max);
    }
    else
        return __1*N;
}

int main(void)
{
    int N, M;

    cin>>N>>M;

    cout<<get_price(N,M)<<endl;

}