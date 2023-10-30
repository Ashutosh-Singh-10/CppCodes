#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        int n;
        cin>>n;
        int temp;
        vector<int> vec,tec;
        vector<int>l,r(n,0);
        int sm=0;
        for(int i=0;i<n;i++)
        {
            
            cin>>temp;
            
            vec.push_back(temp);
            tec.push_back(temp);
            l.push_back(sm);
            sm+=temp;
            
        }
        sm=0;
        for(int i=n-1;i>=0;i--)
        {
            r[i]=sm;
            sm+=temp;

        }
        

    }
}