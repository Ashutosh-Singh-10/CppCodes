#include <iostream>
using namespace std;
// int main()
// {
//     double n,pre,req;
//     cin>>n;
//     pre=n;
//     req=(pre+(n/pre))/2;
//     while(pre-req>0.0000001)
//     {
//         pre=req;
//         req=(pre+(n/pre))/2;
//     }
//     cout<<int(req)<<"."<<int(req*100)%100;
//     return 0;
// }
int main()
{
     char win;
    int winA=0;
    int winB=0;
    for(int i=0;i<20;i++)
    {
        cin>>win;
        if(win=='A') winA++;
        else winB++;
        if(winA>4 && winA-winB>1){ 
            cout<<"A"<<endl;
            return 0;}
        if(winB>4 && winB-winA>1){
             cout<<"B"<<endl;
             return 0;}
    }
    cout<<"Tie"<<endl;
    return 0;
}