#include <bits/stdc++.h>
using namespace std;

int trapping_water(int arr[], int n)
{
    int i=0,ans=0;
    stack<int> st;

    while (i < n)
    {
        while(!st.empty()  && arr[st.top()]<arr[i])
        {
            int curr=st.top();
            st.pop();
            if(st.empty()){
                break;
            }
            int len=i-st.top()-1;
            int height=min(arr[st.top()],arr[i])-arr[curr];
            ans+=len*height;

        }
        st.push(i);
        i++;
    }
    return ans;
}

int main()
{
    int arr[10]={4,2,3,4,5,3,6,5,5,7};
    int k=trapping_water(arr,10);
    cout<<k;
    return 0;
}