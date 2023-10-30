#include  <iostream>
using namespace std;
bool can_put(int **arr,int x,int y,int num)
{
    for(int i=0;i<9;i++)
    {
        if(arr[i][y]==num || arr[x][i]==num) return false;
    }
    int temp1,temp2;
    if (x<3) temp1=0;
    else if(x<6) temp1=3;
    else temp1=6;
    if (y<3) temp2=0;
    else if(y<6) temp2=3;
    else temp2=6;
    for(int i=temp1;i<temp1+3;i++)
    {
        for(int j=temp2;j<temp2+3;j++)
        {
            if(arr[i][j]==num) return false;
        }
    }
    return true;
}
int soduku_solver(int **arr,int x,int y)
{   
    if(x==9)
    {
        y++;
        x=0;
    }
    if(x==9 || y==9) return 1;
    
    if(arr[x][y]==0)
    for(int i=1;i<=9;i++)
    {
        if(can_put(arr,x,y,i))
        {
            arr[x][y]=i;
            if(soduku_solver(arr,x+1,y)) return 1;
            arr[x][y]=0;
        }
    }
    else if (soduku_solver(arr,x+1,y)) return 1;
    return 0;

}
int main()
{
    int **arr=new int*[9];
    for(int i=0;i<9;i++)
    {
        arr[i]=new int[9];
    }
    for(int i=0;i<9;i++)
    {
        for (int j=0;j<9;j++)
        {
            arr[i][j]=0;
        }
    }
    arr[1][0]=6;
    arr[2][0]=7;
    arr[7][0]=1;
    arr[3][1]=3;
    arr[5][1]=9;
    arr[8][1]=5;
    arr[2][3]=2;
    arr[6][3]=6;
    arr[0][4]=3;
    arr[0][5]=9;
    arr[3][4]=5;
    arr[3][5]=4;
    arr[4][6]=6;
    arr[6][6]=2;
    arr[0][7]=8;
    arr[1][7]=5;
    arr[4][8]=1;
    soduku_solver(arr,0,0);
    for (int i=0;i<9;i++)
    {
        for (int j=0;j<9;j++)
        {
            cout<<arr[i][j]<<"  ";
            if(j==2 || j==5)    cout<<"   ";
            
        }
        if(i==2|| i==5) cout<<endl;
        cout<<endl;
    }
    return 0;
}