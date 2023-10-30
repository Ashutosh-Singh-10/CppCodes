#include <bits/stdc++.h>
using namespace std;
int longest_substring_without_repeating_ch(string st)
{
    int arr[26];
    for(int i=0;i<26;i++)
    {
        arr[i]=-1;
    }
    int len=0,max_len=0;
    for(int i=0;i<st.size();i++)
    {
        if(arr[int(st[i])-97]==-1) len++;
        else len=min(len,i-arr[int(st[i])-97]);
        arr[int(st[i])-97]=i;
        if(len>max_len) max_len=len;
        cout<<len<<endl;
    }
return max_len;
}
int main()
{
    string st="bbbbb";
    int ans=longest_substring_without_repeating_ch(st);
    cout<<ans;
    return 0;
}