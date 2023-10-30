#include <bits/stdc++.h>
using namespace std;
int find_peak_element(int arr[],int n)
{
    int start=0,end=n-1,mid;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(mid==0 || mid==n-1 || (arr[mid]>=arr[mid-1] && arr[mid]>=arr[mid+1]))    return mid;
        
        else if (arr[mid]<arr[mid-1]) end=mid-1;
        else if(arr[mid]<arr[mid+1]) start=mid+1;
        
        

    }
    return -1;

}
int main()
{

int arr[]={10,20,30,40,50,55,60};
cout<<find_peak_element(arr,7);



    return 0;
}