#include <iostream>

using namespace std;

int get_count(string &queue, int current_index, int target_number, int max_index)
{
    if(current_index+1 == target_number)
    {
        queue[target_number-1] = '1';
        return 0;
    }
    
    int right_count = 0;
    int index = current_index;
    while(1)
    {
        if(++index >= max_index)
            index -= max_index;

        if(queue[index] == '0')
            right_count+=1;
        
        if(index+1 == target_number)
            break;

    }

    int left_count = 0;
    index = current_index;
    while(1)
    {
        if(--index < 0)
            index += max_index;

        if(queue[index] == '0')
            left_count+=1;

        if(index+1==target_number)
            break;
    }

    queue[target_number-1] = '1';

    return right_count>left_count?left_count:right_count;
}

int get_index(string &queue, int current_index, int max_index)
{
    int index = current_index;
    while(1)
    {
        if(++index >= max_index)
            index -= max_index;

        if(queue[index] == '0')
            return index;
    }
}

int main(void)
{
    int count =0;
    int n, m;

    cin>>n>>m;

    string real_queue ="";
    string &queue = real_queue;

    for(int i=0; i<n; i++)
        real_queue += "0";

    int temp;
    int target[m];

    for(int i=0; i<m; i++)
    {
        cin>>temp;
        target[i] = temp;
    }

    int current;
    int current_index = 0;
    for(int i=0; i<m; i++)
    {
        count += get_count(queue, current_index, target[i], n);
        // cout<<"current count: "<<count<<", current: "<<current_index<<", target: "<<target[i]<<endl;
        if(i!=m-1)
        {
            current_index = get_index(queue, target[i]-1, n);
            // cout<<"new index: "<<current_index<<endl;
        }
    }

    cout<<count<<endl;
}