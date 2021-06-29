#include <iostream>

using namespace std;

pair<int, int> get_first_one(int N, int L)
{
    pair<int, int> answer;
    for(int i=L; (i<=100)||(i<N/2); i++)
    {
        double a = (double)N/i - (double)(i-1)/2;

        if (a - int(a) == 0)
        {
            answer.first = a;
            answer.second = i;

            return answer;
        }
    }

    answer.first = -1;

    return answer;
}

int main(void)
{
    int N, L;

    cin>>N>>L;

    pair<int, int> answer = get_first_one(N, L);

    if(answer.first < 0 || answer.second > 100)
        cout<<-1;
    else
        for(int i=0; i<answer.second; i++)
            cout<<answer.first+i<<" ";

    return 0;
}