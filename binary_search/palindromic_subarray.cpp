#include <bits/stdc++.h>
using namespace std;
bool is_palindrome(int arr[],int n,int start,int end)
{
    while(end>start)
    {
        if(arr[start]!=arr[end]) return false;
        end--;
        start++;
    }
    return true;
}
bool has_palindrome(int arr[],int n,int k)
{
    bool ans=false;
    
    for(int i=0;i<=n-k;i++)
    {
        if(is_palindrome(arr,n,i,i+k-1)) return true;
    }
return false;

}

int main()
{

    int arr[]={1,2,1,4,5};
cout<<has_palindrome(arr,5,1);
    return 0;
}