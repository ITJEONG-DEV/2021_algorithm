#include <iostream>

using namespace std;

int get_square_size(int N, int M)
{
    int length = N>M?M:N;

    int arr[N][M];
    char a;

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
        {
            cin>>a;
            arr[i][j] = int(a);
        }

    while(length>1)
    {
        for(int i=0; i<N-length+1; i++)
        {
            for(int j=0; j<M-length+1; j++)
            {
                int value = arr[i][j];

                if(value == arr[i][j+length-1] && value == arr[i+length-1][j] && value == arr[i+length-1][j+length-1])
                    return length;
            }
        }

        --length;
    }

    return length;
}

int main(void)
{
    int N, M;

    cin>>N>>M;

    int answer = get_square_size(N, M);

    cout<<answer*answer<<endl;

    return 0;
}