#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    
    
    for(int l=0;l<t;l++)
    {

        int n,k,temp,ans=INT_MAX;
        cin>>n>>k;
        if(k==4)
        {
            int ev=0;
            int od=0;
            int x=0;
            for(int i=0;i<n;i++)
            {
            cin>>temp;

                if(temp%2)
                {
                    od++;
                }
                else{
                    ev++;
                }
                if(temp%4==3 )
                {
                    x++;
                }
                else if(temp%4==0)
                {
                    ev+=2;
                }
            }

// cout<<"#######";
            if(ev>=2)
            {
                cout<<0<<endl;
            }
            else if(ev==1 || x>=1)
            {
                cout<<1<<endl;
            }
            
            else 
            {
                cout<<2<<endl;
            }



        }
        else
        {for(int i=0;i<n;i++)
        {
            cin>>temp;
            if(temp%k==0)
            {
                ans=0;

            }
            ans=min(ans,k-(temp%k));

        }
        // cout<<"##########"<<
        cout<<ans<<endl;
}

    }
    return 0;

}