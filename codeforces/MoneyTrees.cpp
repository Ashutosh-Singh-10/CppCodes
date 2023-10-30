#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,k,sz,ans,sum;
    cin>>t;
    int n,temp,prev;
    vector<int> vec,fruits;
    queue<int> q;
    // int ans=0;
    for(int l=0;l<t;l++)
    {
        cin>>n ;
        cin>>k;
        sz=0;
        ans=0;
        vec.clear();
        fruits.clear();
        sum=0;
        while(q.size())
        {
            q.pop();
        }
        for(int f=0;f<n;f++)
        {
            cin>>temp;
            fruits.push_back(temp);
        }
        for(int f=0;f<n;f++)
        {
            cin>>temp;
            vec.push_back(temp);
        }
        prev=vec[0];
    sz=0;
    for(int i=0;i<n;i++)
    {
        if(prev%vec[i]==0)
        {
            sum+=fruits[i];
            // sz++;
            q.push(fruits[i]);
        }
        else
        {
            sum=fruits[i];
            // sz=1;
            while(q.size())
            {
                q.pop();
            }
            q.push(fruits[i]);
        }
        while(sum>k)
        {
            sum-=q.front();
            q.pop();
        }
        ans=max(ans,(int)q.size());
        prev=vec[i];
        
    }
    cout<<ans<<endl;
    
        
        
        
        
        

    }
    return 0;

}