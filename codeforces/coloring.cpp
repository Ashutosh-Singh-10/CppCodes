#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int l=0;l<t;l++)
    {
        int n,m,k,temp,cnt=0;
        cin>>n>>m>>k;
        int mx=0;
        for(int i=0;i<m;i++)
        {
            cin>>temp;
            if(temp==mx)
            {
                cnt++;
            }
            else if(temp>mx)
            {
                cnt=1;
                mx=temp;
            }
            

            
        }
        int tot=n/k;
        if(n%k)
        {
            tot++;
        }
        // cout<<mx<<"  "<<tot<<"  "<<cnt<<" "<<n%k<<endl;
        if(mx<tot || (tot==mx     && (cnt<=n%k || n%k==0)))
        {
            cout<<"Yes";
        }else cout<<"No";
        cout<<endl;




    }
    return 0;

}