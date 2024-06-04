#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s ;
    vector<int> vec(26,0);
    for(auto &i:s)
    {
        vec[i-'A']++;
    }
    int cnt=0;
    int ans=0;
    for(int i=0;i<26;i++)
    {
        if(vec[i]&1)
        {
            cnt++;
            ans=i;
        }
    }
    if(cnt>1)
    {
        cout<<"NO SOLUTION";
        return 0;
    }
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<vec[i]/2;j++)
        {
            cout<<char(i+'A');
        }
        
    }
    if(cnt) cout<<char(ans+'A');
    for(int i=25;i>=0;i--)
    {
        for(int j=0;j<vec[i]/2;j++)
        {
            cout<<char(i+'A');
        }
        
    }

    return 0;
}