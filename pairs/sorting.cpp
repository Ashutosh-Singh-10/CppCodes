#include <bits/stdc++.h>
using namespace std ;
int main()
{
    int n;
    cin>>n;
    pair<int ,int> arr[n];
    int a,b;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        cin>>b;
        arr[i]={a,b};
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i].first<<" "<<arr[i].second<<endl;
    }


    return  0;
}