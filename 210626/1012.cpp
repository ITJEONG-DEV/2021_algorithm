#include <iostream>
#include <vector>

using namespace std;

int **field;

void count(int x, int y, int width, int height)
{
    ::field[y][x] = 0;

    if(y>0)
        if(::field[y-1][x]==1)
            count(x, y-1, width, height);
    
    if(y+1<height)
        if(::field[y+1][x]==1)
            count(x, y+1, width, height);

    if(x>0)
        if(::field[y][x-1]==1)
            count(x-1, y, width, height);
    
    if(x+1<width)
        if(::field[y][x+1]==1)
            count(x+1, y, width, height);

}

int earth_worm()
{
    int answer=0;

    int m, n, k;

    cin>>m>>n>>k;


    field = new int *[n];
    for(int i=0; i<n; i++)
    {
        ::field[i] = new int[m];

        for(int j=0; j<m; j++)
            ::field[i][j] = 0;
    }

    int x, y;
    for(int i=0; i<k; i++)
    {
        cin>>x>>y;
        ::field[y][x] = 1;
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if (::field[i][j] == 1)
            {
                count(j,i,m,n);
                answer+=1;
            }
    
    for(int i=0; i<n; i++)
        delete field[i];
    
    delete field;

    return answer;
}

int main(void)
{
    int n;

    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<earth_worm()<<endl;
    }

    return 0;
}