#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,k,sz,ans,sum;
    cin>>t;
    
    
    for(int l=0;l<t;l++)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        unordered_map<char,int> mp;
        for(auto &i:s)
        {
            mp[i]++;
        }
        int o=0,e=0;
        for(auto &i:mp)
        {
            if(i.second%2)
            {
                o++;
            }
            else{
                e++;
            }

        }
        if(o>k+1)
        {
            cout<<"NO"<<endl;
        }
        else cout<<"Yes"<<endl;

        

    }
    return 0;

}