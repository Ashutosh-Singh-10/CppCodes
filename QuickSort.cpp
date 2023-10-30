#include <iostream>
using namespace std;
int partition(int *arr,int start,int end)
{
    int temparr[end-start];
    for(int i=0;i<end-start;i++)
    {
        temparr[i]=arr[start+i];
    }
    int i=0;
    int temp=arr[end];
    while(start!=end)
    {
        if (temp>temparr[i])
        {
            arr[start]=temparr[i];
            start++;
        }
        else{
            arr[end]=temparr[i];
            end--;
        }
        i++;
        arr[start]=temp;
    }
    return start;

}
void countSort(int *arr,int start,int end)
{
    if(start==end) return;
    int pos=partition(arr,start,end-1);
    countSort(arr,start,pos);
    countSort(arr,pos+1,end);

    return ;
}
int main()
{
    int arr[11]={2,42,4,25,25,55,23,66,88,99,34};
    countSort(arr,0,11);
    for(int i=0;i<11;i++)
    {
        cout<<arr[i]<<"  ";
    }

    return 0;
}