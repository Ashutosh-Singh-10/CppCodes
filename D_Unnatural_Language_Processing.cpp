#include <bits/stdc++.h>
using namespace std;

void solve();
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
void solve()
{   
    int n;
    cin>>n;
    string s;
    cin>>s;
    int flag=0;
    for(int i=0;i<s.length();i++)
    {
        if(i==n-1 || s[i+1]=='a' || s[i+1]=='e')
        {
            if(flag==0)
            {
                flag=1;
            }
            

        }
    }
  
}

    