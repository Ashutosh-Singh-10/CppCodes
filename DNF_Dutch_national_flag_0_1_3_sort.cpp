#include <iostream>
using namespace std;

int main()
{
    int arr[11]={1,2,0,0,1,1,2,1,2,0,0};
    int start=0,mid=0,end=10;
    int temparr[11];
    for(int i=0;i<11;i++)
    {
        temparr[i]=0;
    }
    for(int i=0;i<11;i++)
    {
        if(arr[i]==2)
        {
            temparr[end]=2;
            end--;
        }
        else
        {
            if(arr[i]==0)
            {
                temparr[start]=0;
                start++;
            }
            temparr[mid]=1;
            mid++;

        }
    }
     for(int i=0;i<11;i++)
    {
        cout<<temparr[i]<<"   ";
    }

    return 0;
}