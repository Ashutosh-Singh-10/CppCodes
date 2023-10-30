#include <iostream>
using namespace std;
int main()
{
    int n=47;
    int arr[n+1];
    for(int i=0;i<n+1;i++)
    {
        arr[i]=0;
    }
    for (int i=2;i<n;i++)
    {
        if (arr[i]==0)
        {
            for (int j=i;j*i<=n;j++)
            {
                if (arr[j*i]==0)
                {
                    arr[j*i]=1;
                }
            }

        }
    }
    for (int i=2;i<=n;i++)
    {
        if(arr[i]==0)
        {
            cout<<i<<endl;
        }
    }


    return 0;
}