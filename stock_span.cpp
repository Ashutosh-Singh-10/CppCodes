#include <bits/stdc++.h>
using namespace std;
vector<int> stock_span(int arr[],int n)
{
    int i=0;
    vector<int> ans;
    stack <int> st;
    while(i<n)
    {
        if(st.empty())
        {
           
            ans.push_back(i+1);
        }
        else{

            while(arr[st.top()]<arr[i])
            {
                st.pop();
            }
            ans.push_back(i-st.top());
            
        }
        st.push(i);
        i++;
    }
    
    return ans;
}
int main()
{
    int arr[]={100,80,60,70,60,75,85};
    
    for(auto i:stock_span(arr,7))
    {
        cout<<i<<" ";
    }
    return 0;
}