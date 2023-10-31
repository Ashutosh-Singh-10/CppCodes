#include <bits/stdc++.h> 
using namespace std;


bool algo(vector<int>  &  x,int val,int k)
{
    int p=x[0];
    int cnt=1;
    for(int i=1;i<x.size();i++)
    {
        if(x[i]-p>=val)
        {
            cnt++;
            p=x[i];
        }
    }
    if(cnt>=k) return 1;
    return 0 ;
}
int maximizeMinimumDistance(vector<int> x,int k)
{
    sort(x.begin(),x.end());
    int last=x[x.size()-1];
    int start=0;
    int mid;
    if(algo(x,last,k)) return last;
    while(start<last)
    {
        mid=start+(last-start)/2;
        if(algo(x,mid,k))
        {
            start=mid+1;
        }
        else
        {
            last=mid;
        }
        
        
    }   
    if(algo(x,mid,k)) return mid;
    
    return mid-1;

}

int main()
{
 
 vector<int> vec={3,10,14,8,7};
 cout<<maximizeMinimumDistance(vec,4);

    return 0;
}