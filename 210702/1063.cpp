#include <iostream>

using namespace std;

typedef pair<int, int> Index;
typedef pair<string, string> Positions;

const int size = 8;

bool equal(Index a, Index b);
Index get_index(string position);
Index move(Index current, Index movement);
Index move_object(Index current, string command);
Positions make_position(Index king, Index stone);
Positions get_positions();

int main(void)
{
    Positions positions = get_positions();

    cout<<positions.first<<endl<<positions.second<<endl;

    return 0;
}

bool equal(Index a, Index b)
{
    return a.first==b.first && a.second==b.second;
}

Index get_index(string position)
{
    Index index;

    index.first = int(::size - (position[1] - '0'));
    index.second = int(position[0] - 'A');

    return index;
}

Index move(Index current, Index movement)
{
    int new_first = current.first + movement.first;
    int new_second = current.second + movement.second;

    if(new_first < 0 || new_first > ::size-1 || new_second < 0 || new_second > ::size-1)
        return current;
    
    current.first = new_first;
    current.second = new_second;

    return make_pair(new_first, new_second);
}

Positions make_positions(Index king, Index stone)
{
    Positions positions;

    string first;
    first += ((char)king.second + 'A');
    first += (char)(::size - king.first + '0');
    
    string second;
    second += ((char)stone.second + 'A');
    second += (char)(::size - stone.first + '0');

    return make_pair(first, second);
}

Index move_object(Index current, string command)
{
    Index index;
    if(command=="R")
        index = make_pair(0, 1);
    else if(command=="L")
        index = make_pair(0, -1);
    else if(command=="B")
        index = make_pair(1, 0);
    else if(command=="T")
        index = make_pair(-1, 0);
    else if(command=="RT")
        index = make_pair(-1, 1);
    else if(command=="LT")
        index = make_pair(-1, -1);
    else if(command=="RB")
        index = make_pair(1, 1);
    else if(command=="LB")
        index = make_pair(1, -1);
    else
        index = make_pair(0, 0);

    return move(current, index);
}

Positions get_positions()
{
    Positions positions;
    int n;

    cin>>positions.first>>positions.second>>n;

    Index king = get_index(positions.first);
    Index stone = get_index(positions.second);

    string command;
    Index new_king, new_stone;
    for(int i=0; i<n; i++)
    {
        cin>>command;
        new_king = move_object(king, command);

        if(!equal(king, new_king))
        {
            if(equal(new_king, stone))
            {
                new_stone = move_object(stone, command);

                if(!equal(stone, new_stone))
                {
                    king = new_king;
                    stone = new_stone;
                }
            }
            else
                king = new_king;
        }
    }

    return make_positions(king, stone);
}
