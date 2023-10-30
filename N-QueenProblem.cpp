#include <iostream>
using namespace std;
int canDiagonally(int **arr,int s,int t,int n,int fsign,int ssign)
{
    while(s<n  && s>-1 && t>-1 && t<n)
    {
        if (arr[s][t]==1)
        {
            return 0;
        }
        s+=fsign; 
        t+=ssign;
    }
    return 1;
}
int canPut(int **arr,int s,int t,int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[s][i]==1)
        return 0;
        if(arr[i][t]==1)
        return 0;
    }
    if (!canDiagonally(arr,s,t,n,1,1)) return 0;
    else if (!canDiagonally(arr,s,t,n,-1,-1)) return 0;
    else if (!canDiagonally(arr,s,t,n,-1,1)) return 0;
    else if (!canDiagonally(arr,s,t,n,1,-1)) return 0;


    return 1;

}
int nQueen(int **arr,int s,int t, int n)
{
    if (s==n)
    {
        
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                cout<<arr[i][j]<<"  ";
            }cout<<endl;
        }
        return 1;
    }
    for(int i=0;i<n;i++)
    {
        cout<<"yeah "<<s<<" "<<i<<endl;
        if(canPut(arr,s,i,n))
        {
            arr[s][i]=1;
            if (nQueen(arr,s+1,i,n))
            {
                return 1;
            }
            arr[s][i]=0;
        }
    }
    cout<<"nooooo"<<endl;
    return 0;
}

int main()
{
    int n=10;
    int **arr=new int *[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
       for (int j=0;j<n;j++)
       {
           arr[i][j]=0;
       }
    }
    
    nQueen(arr,0,0,n);
    return 0;
}


