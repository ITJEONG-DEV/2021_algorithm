#include <iostream>
#include <list>
#include <cmath>

using namespace std;

typedef pair<int, int> Center;
typedef pair<Center, int> Planet;

double get_distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow((x1-x2),2) + pow((y1-y2),2));
}

bool is_in_planet(int x, int y, Planet planet)
{
    int cx = planet.first.first;
    int cy = planet.first.second;
    int r = planet.second;

    if ( get_distance(x, y, cx, cy) < r)
        return true;
    else
        return false;
}

int get_count(void)
{
    int count = 0;

    int x1, y1, x2, y2;

    cin>>x1>>y1>>x2>>y2;

    int n;

    cin>>n;

    int cx, cy, r;
    for(int i=0; i<n; i++)
    {
        cin>>cx>>cy>>r;

        Center center = make_pair(cx, cy);
        Planet planet = make_pair(center, r);

        bool is_origin_in_planet = is_in_planet(x1, y1, planet);
        bool is_destination_in_planet = is_in_planet(x2, y2, planet);

        if(is_in_planet(x1, y1, planet) != is_in_planet(x2, y2, planet))
            count++;
    }

    return count;
}

int main(void)
{
    int T;

    cin>>T;

    for(int i=0; i<T; i++)
        cout<<get_count()<<endl;

    return 0;
}