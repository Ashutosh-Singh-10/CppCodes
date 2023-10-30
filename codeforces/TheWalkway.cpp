#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t=0;
    cin>>t;
    long long n,x,d,temp;
    for(int l=0;l<t;l++)
    {
        cin>>n>>x>>d;
        vector<long long> vec;
        for(int i=0;i<x;i++)
        {
            cin>>temp;
            if(temp!=1)
            vec.push_back(temp);
        }
        sort(vec.begin(),vec.end());
        vec.push_back(n);

        long long prev=1;
        long long cnt;
        long long mx,cook=0;
        int tt=1;
        int z=0;
    
        for(int i=0;i<vec.size()-1;i++)
        {
            
            cook+=(vec[i]-prev)/d;
            cnt=(vec[i]-prev)/d;
            if((vec[i]-prev)%d)
            {

                cook++;
                cnt++;
            }
            cnt+=(vec[i+1]-vec[i])/d;
            mx=(vec[i+1]-prev)/d;
            if(mx<cnt)
            {
                z++;
            }
            
        prev=vec[i];


        }
        cook+=(n-prev)/d;
        if((n-prev)%d)
        {
            cook++;
        }
        cout<<cook-1<<" "<<z<<endl<<endl;
        


    }


    return 0;
}