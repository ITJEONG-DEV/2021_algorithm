#include <iostream>

using namespace std;

const int size = 8;
bool ** board;

int calculate(int start_i, int start_j, int min)
{
    // start with W(true)
    int wrong_count = 0;
    for(int i=0; i<::size; i++)
        for(int j=0; j<::size; j++)
            if((!(i%2) && !(j%2) || i%2 && j%2)&&!board[start_i+i][start_j+j])
                ++wrong_count; 
            else if( (!(i%2) && j%2 || i%2 && !(j%2)) && board[start_i+i][start_j+j])
                ++wrong_count;
    
    return wrong_count>::size*::size/2?::size*::size-wrong_count:wrong_count;
}

int redraw(int n, int m)
{
    int current_min = 64;

    char temp;

    board = new bool*[n];
    for(int i=0; i<n; i++)
    {
        board[i] = new bool[m];
        for(int j=0; j<m; j++)
        {
            cin>>temp;

            if(temp=='W')
                board[i][j] = true;
            else
                board[i][j] = false;
        }
    }

    int number;
    for(int i=0; i<n-(::size-1); i++)
        for(int j=0; j<m-(::size-1); j++)
        {
            number = calculate(i, j, current_min);
            current_min = current_min<number?current_min:number;
        }
    
    return current_min;
}

int main(void)
{
    int n, m;

    cin>>n>>m;

    cout<<redraw(n, m)<<endl;

    return 0;
}