#include <iostream>
#include <vector>

using namespace std;

bool is_in_it(int n, vector<int> vt)
{
    vector<int>::iterator iter;

    for(iter=vt.begin(); iter != vt.end(); ++iter)
        if( (*iter) == n)
            return true;
    
    return false;
}

int get_famous_person(int N)
{
    vector<int> person[N];

    char character;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            cin>>character;

            if(character == 'Y')
                person[i].push_back(j);
        }

    int num_of_friends = 0;

    vector<int>::iterator iter;
    vector<int>::iterator inner_iter;
    vector<int> friends;
    for(int i=0; i<N; i++)
    {
        friends.clear();
        for(iter=person[i].begin(); iter != person[i].end(); ++iter)
        {
            if(!is_in_it(*iter, friends))
                friends.push_back(*iter);

            for(inner_iter=person[*iter].begin(); inner_iter != person[*iter].end(); ++inner_iter)
                if(i != *inner_iter && !is_in_it(*inner_iter, friends))
                    friends.push_back(*inner_iter);
        }
        
        int size = friends.size();
        if(size > num_of_friends)
            num_of_friends = size;
    }

    return num_of_friends;
}

int main(void)
{
    int N;

    cin>>N;

    cout<<get_famous_person(N)<<endl;

    return 0;
}