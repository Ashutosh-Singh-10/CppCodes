#include <bits/stdc++.h>
using namespace std;
int catalan_number(int n)
{
    if(n<=1) return 1;
    int arr[n];
    arr[0]=1;
    arr[1]=1;
    int temp;
    for(int i=2;i<n;i++)
    {
        temp=0;
        for(int j=0;j<=(i-2)/2;j++)
        {   
            temp+=arr[j]*arr[i-1-j]*2;
        }
        if(i%2)
        {
            temp+=arr[i/2]*arr[i/2];
        }
        arr[i]=temp;
    }
    return arr[n-1];

}
int main()
{
    cout<<catalan_number(7);
    return 0;
}