#include <bits/stdc++.h>
using namespace std;
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
       for(auto &i:vec)
       {
        cout<<i<<"  ";
       }
       cout<<endl;
       int end=n-1;
       int start=0;
       int x=0;
       int ans=0;
       int vac=0;
       while(start<end)
       {
        if(vec[start]+x>vec[end])
        {
            if(end-start==1)
            {
                ans+=vec[end]-x+1;
                vac=vec[start]+x-vec[end];
                break;
            }
            else
            {
                ans+=vec[end]-x+1;
                end--;
                x=vec[start]+x-vec[end];
                
            }
        }
        else if(vec[start]+x<vec[end])
        {

            if(end-start==1)
            {
                ans+=vec[start]+x;
                vac=vec[end]-vec[start]-x;
                break;

            }
            else
            {
                x+=vec[start];
                ans+=vec[start];
                start++;

            }

        }
        else 
        {
            ans+=vec[start]+1;

            if(end-start==2)
            {
                vac=vec[start+1];
                break;

            }
            else if(end-start==1) 
            {
            break;
            }
            start++;
            end--;
            x=0;

        }
        cout<<"#######"<<start<<"  "<<end<<"   "<<ans<<"  "<<endl;

       }
        cout<<endl;
        cout<<ans<<endl;

        if(vac<3)
        {
            ans+=vac;
        }
        else
        {
            ans+=vac/2;
            if(ans%2) ans++;
            ans++;
        }
        cout<<ans<<endl;
        // cout<<endl;

      
    }
    return 0;

}