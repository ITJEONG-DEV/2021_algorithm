#include <iostream>
#include <vector>

using namespace std;

pair<int, int> get_maximum_interval(vector<int> S, int n)
{
    pair<int, int> interval;

    if(S.size() == 1 || n < S.front())
    {
        interval.first = 1;
        interval.second = S.front()-1;

        return interval;
    }

    vector<int>::iterator iter, iter2;
    for(iter=S.begin(), iter2=++S.begin(); iter!=S.end() && iter2!=S.end(); ++iter, ++iter2)
    {
        if(*iter==n || *iter2==n)
        {
            interval.first = -1;
            return interval;
        }
        else if(*iter<n && n<*iter2)
        {
            interval.first = *iter+1;
            interval.second = *iter2-1;
            return interval;
        }
    }

    interval.first = -1;
    return interval;
}

int get_number_of_intervals()
{
    int L, n;

    cin>>L;

    vector<int> S;
    vector<int>::iterator iter;

    for(int i=0; i<L; i++)
    {
        cin>>n;
        for(iter=S.begin(); iter!=S.end(); ++iter)
            if(*iter > n)
            {
                S.insert(iter, n);
                break;
            }
        
        if(iter==S.end())
            S.push_back(n);
    }

    // cout<<"vector: ";
    // for(iter=S.begin(); iter!=S.end(); ++iter)
    //     cout<<*iter<<" ";
    // cout<<endl;

    cin>>n;

    pair<int, int> interval = get_maximum_interval(S, n);

    if(interval.first==-1)
        return 0;
    else if(interval.first==n || interval.second == n)
        return (interval.second - interval.first);
    else
        return (interval.second - n + 1)*(n - interval.first + 1) - 1;
}

int main(void)
{

    cout<<get_number_of_intervals()<<endl;

    return 0;
}