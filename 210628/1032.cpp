#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    int N;
    cin>>N;

    string answer;
    string target;

    cin>>answer;

    int length = answer.length();

    string::iterator start;
    string::iterator temp;
    for(int i=0; i<N-1; i++)
    {
        cin>>target;

        for(start = answer.begin(), temp = target.begin(); start != answer.end() && temp != answer.end(); ++start, ++temp)
        {
            if(*start != *temp)
                *start = '?';
        }
    }

    cout<<answer;

    return 0;
}