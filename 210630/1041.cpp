#include <iostream>

using namespace std;

inline int get_max(int a, int b)
{
    return a>b?a:b;
}

inline int get_min(int a, int b)
{
    return a>b?b:a;
}

void swap(int &a, int &b)
{
    a^=b^=a^=b;
}

void sort(int *arr, int length, bool ascending=true)
{
        for(int i=0; i<length-1; i++)
            for(int j=i+1; j<length; j++)
                if(arr[i]>arr[j]&&ascending || arr[i]<arr[j]&&!ascending)
                    swap(arr[i], arr[j]);
}

// BOJ에서는 __int64_t 가 유효한 타입이었음 (언어: C++17)
__int64 get_minimum_sum(int dice[6], __int64 N)
{
    __int64 sum = 0;    

    if(N==1)
    {
        sort(dice, 6);

        for(int i=0; i<5; i++)
            sum+=dice[i];

    }
    else
    {
        int a[3] = { get_min(dice[0], dice[5]), get_min(dice[1], dice[4]), get_min(dice[2],dice[3])};

        sort(a, 3);

        sum = N*( 5*a[0]*N + 8*(a[1]-a[0]) ) + 4*(a[0]-2*a[1]+a[2]);
    }

    return sum;
}

int main(void)
{
    long N;

    cin>>N;

    int dice[6];

    for(int i=0; i<6; i++)
        cin>>dice[i];

    cout<<get_minimum_sum(dice, N);

    return 0;
}