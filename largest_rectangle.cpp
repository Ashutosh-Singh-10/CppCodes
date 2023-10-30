#include <bits/stdc++.h>
using namespace std;
void show_stack(stack<int>st,vector<int>arr)
{
    while(!st.empty())
    {
        cout<<"   "<<arr[st.top()];
        st.pop();
    }
    cout<<endl;
}
int largest_rectangle(vector <int> arr,int n)
{
    
    arr.push_back(0);
    stack<int> st;
    int ans=0,i=0;
    while(i<=n)
    {
        
        while(!st.empty() && arr[st.top()]>arr[i])
        {
            
            int height=arr[st.top()];
            st.pop();
            if(st.empty())
            {
                ans=max(i*height,ans);
                break;
            }
            int width=i-st.top()-1;
            ans=max(ans,height*width);
         
           
        }
        st.push(i);   
        i++;
    }
    
    return ans;

}
int main()
{
    vector<int > arr={1,3,5,2,5,2};

    int k=largest_rectangle(arr,arr.size());
    

    cout<<"The answer is "<<k;

    return 0;
}