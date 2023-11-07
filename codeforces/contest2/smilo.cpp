#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    long long t,temp;
    cin>>t;

    
    for(long long l=0;l<t;l++)
    {
        int n;
       cin>>n;
       vector<int> vec;
       for(int i=0;i<n;i++)
       {
        cin>>temp;
        vec.push_back(temp);
       }
       sort(vec.begin(),vec.end());
    //    for(auto &i:vec)
    //    {
    //     cout<<i<<"  ";
    //    }
    //    cout<<endl;
       int end=n-1;
       int start=0;
       ll x=0;
       ll ans=0;
       ll vac=0;
       ll left=0,right=0,cnt=0;
       while(start<end)
       {
        if(left>=right+vec[end])
        {
            right+=vec[end];
            cnt++;
            end--;
        }
        else
        {
            left+=vec[start];
            start++;
        }

       
       }
       ans+=right+cnt;
    //    cout<<"#########"<<ans<<endl;
       vac=vec[start];
       x=left-right;
       if(vac<=x)
       {
            ans+=vac+1;
            x=x-vac;
       }
       else
       {
        x=vac+x;
        


       }
            if(x<3)
            {
                ans+=x;
            }
            else
            {
                ans+=x/2;
                ans++;
                ans+=(x%2==1)?1:0;
            }
            // cout<<"#########";
            cout<<ans<<endl;


  

        

      
    }
    return 0;

}