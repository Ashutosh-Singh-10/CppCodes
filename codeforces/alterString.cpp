#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long mod=998244353;
                        
 
    long long ans=1;
    string s;
    long long t,tot=0;
    cin>>t;
    char pr='a';
    long long cnt;
    for(int l=0;l<t;l++)
    {
        cin>>s;
        pr='a';
        cnt=0;
        tot=0;
        ans=1;
        for(auto &i:s)
        {
            if(pr!=i)
            {
                ans*=cnt%mod;
            ans%=mod;
                cnt=1;

            }
            else
            {
                tot++;
                cnt++;
            }
            ans=ans==0?1:ans;
            
            pr=i;
        }
          ans*=cnt%mod;
            ans%=mod;
        // cout<<ans<<endl;
        int an2=tot;
        while(tot>1)
        {
            ans*=tot;
            ans%=mod;
            tot--;
        }
        cout<<an2<<" "<<ans<<endl;

        
        
    }
    return 0;
}