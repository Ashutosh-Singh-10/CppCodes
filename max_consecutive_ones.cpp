#include <bits/stdc++.h>
using namespace std;
int max_cons_ones(int arr[],int n,int zero_allowed)
{
   queue<int> q;
   int i=0,curr_max=0,max=0,zero_used=0;
   
   while(i<n)
   {
       if(arr[i]==1)
       {
           curr_max++;
       }
       else
       {
           q.push(i);
           zero_used++;
           curr_max++;
       }
       if(zero_used>zero_allowed)
       {
           
           curr_max=i-q.front();
           zero_used--;
           q.pop();
       }
       if(curr_max>max)
       {
           max=curr_max;
       }
       i++;
       cout<<curr_max<<"   "<<max<<endl;

   } 
    return max;





}


int main()
{
    int arr[]={0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int ans=max_cons_ones(arr,19,3);
    cout<<ans;
    return 0;
}