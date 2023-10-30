#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t,temp;
    cin>>t;
    long long  ws=1;
    vector<long long> vec={1};
    for(long long i=1;i<=30;i++)
    {
        ws*=2;
        vec.push_back(ws);
    }
    // for(auto i:vec)
    // {
    //     cout<<i<<"  ";
    // }
    // cout<<endl;
    
    
    for(long long l=0;l<t;l++)
    {
        
        long long n,q;
        cin>>n>>q;
        vector<long long> nums,query,help;

        for(long long i=0;i<n;i++)
        {
            cin>>temp;
            nums.push_back(temp);
        }
        long long qmx=INT_MAX;
        for(long long i=0;i<q;i++)
        {
            cin>>temp;
            if(temp<qmx)
            {

            query.push_back(temp);
            qmx=temp;
            }
            
        }
        long long add=0;

        for(auto &i:nums)
        {
            add=0;
            for(auto &j:query)
            {
                if(i%vec[j]==0)
                {
                    add+=vec[j-1];
                }

            }
            cout<<i+add<<"  ";
        }

        cout<<endl;
        // cout<<endl;
        

        
      
    }
    return 0;

}