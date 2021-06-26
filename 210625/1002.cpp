#include <iostream>
#include <cmath>

using namespace std;

int get_possible_position(int x1, int y1, int r1, int x2, int y2, int r2)
{
    if (x1==x2 && y1==y2)
        if(r1==r2)
            return -1;
        else
            return 0;

    double distance = sqrt(pow((x1-x2),2) + pow((y1-y2),2));

    int r_sum = r1+r2;
    int r_dif = abs(r1-r2);

    if (distance > r_sum)
        return 0;
    else if (distance == r_sum)
        return 1;
    else if (distance < r_sum && distance > r_dif)
        return 2;
    else if (distance == r_dif)
        return 1;
    else
        return 0;
}

int main(void)
{
    int n;

    cin>>n;

    for(int i=0; i<n; i++)
    {
        int x1, y1, r1, x2, y2, r2;

        cin>>x1>>y1>>r1>>x2>>y2>>r2;

        cout<<get_possible_position(x1,y1,r1,x2,y2,r2)<<endl;
    }
    
    return 0;
}