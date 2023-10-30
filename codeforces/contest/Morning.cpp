#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,k,sz,ans,sum;
    cin>>t;
    
    
    for(int l=0;l<t;l++)
    {
        string num;
        cin>>num;
        int curr=1;
        int dig=0;
        int ans=0;
        for(auto &i:num)
        {
            if(i=='0')
            {
                dig=10;
            }
            else 
            {
                dig=i-'0';
            }
            ans+=abs(curr-dig);
            curr=dig;
            

        }
        cout<<ans+4<<endl;
        



        

        

    }
    return 0;

}