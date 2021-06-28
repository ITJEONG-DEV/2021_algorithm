#include <iostream>
#include <list>
#include <tuple>

using namespace std;

typedef pair<int, pair<int, int>> Item;

void print_item_list(list<Item> items)
{
    list<Item>::iterator it;
    for(it = items.begin(); it != items.end(); ++it)
    {
        cout<<"<"<<(*it).first<<" <"<<(*it).second.first<<", "<<(*it).second.second<<"> >"<<endl;
    }
}

int main(void)
{
    int n;
    cin>>n;

    // <int number, <int origin_index, int new_index>>
    list<Item> item_list;
    list<Item>::iterator it;

    // read
    int num;
    for(int i=0; i<n; i++)
    {
        cin>>num;

        Item item = make_pair(num, make_pair(i, i));

        // insert
        if(i==0)
        {
            item_list.push_back(item);
            continue;
        }


        int first;
        for(it = item_list.begin(); it != item_list.end(); ++it)
        {
            first = (*it).first;

            if(num<first || it==item_list.end())
                break;
        }

        item_list.insert(it, item);

        // cout<<"[insert]"<<endl;
        // print_item_list(item_list);

    }

    // set new index
    int count = 0;
    for(it = item_list.begin(); it != item_list.end(); ++it, count+=1)
    {
        (*it).second.second = count;
    }

    // cout<<"[set new index]"<<endl;
    // print_item_list(item_list);


    // reorder using origin_index
    for(it = item_list.begin(); it != item_list.end(); ++it)
    {
        list<Item>::iterator it2 = it;
        for(; it2 != item_list.end(); it2++)
        {
            if ( (*it).second.first > (*it2).second.first )
            {
                (*it).swap(*it2);
            }
        }
    }

    // print
    for(it = item_list.begin(); it != item_list.end(); ++it)
    {
        cout<<(*it).second.second<<" ";
    }
    cout<<endl;
    // cout<<"[print]"<<endl;
    // print_item_list(item_list);

    return 0;
}