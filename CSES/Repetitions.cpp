#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int cnt=1;
    int ans=1;
    for(int i=1;i<s.length();i++)
    {
        if(s[i]==s[i-1])
        {
            cnt++;
        }
        else 
        {
            cnt=1;
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}