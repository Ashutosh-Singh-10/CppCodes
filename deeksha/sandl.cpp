#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<int,int> snake,ladder;
    snake[99]=17;
    snake[79]=25;
    snake[66]=47;
    snake[35]=4;
    ladder[7]=31;
    ladder[70]=81;
    ladder[55]=90;
    ladder[40]=61;

    int in,curr=0,step=0;
    while(1)
    {
        cin>>in;
        if(in+curr>100)
        {
            cout<<"step"<<step;
            break;
        }
        curr+=in;
        if(snake.count(curr))
        {
            curr=snake[curr];
        }
        else if(ladder.count(curr))
        {
            curr=ladder[curr];
        }
        step++;
        cout<<curr<<"  ";
    }
    return 0;
}