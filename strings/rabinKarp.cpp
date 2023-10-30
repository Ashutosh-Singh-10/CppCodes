#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a="abdabcdacbdabcbdcab";
    string b="abc";
    int hasha=0,hashb=0;
    for(int i=0;i<b.size();i++)
    {
        hasha*=b.size();
        hasha+=a[i]-'a'+1;
    }
    for(int i=0;i<b.size();i++)
    {
        hashb*=b.size();
        hashb+=b[i]-'a'+1;
    }
    int d=pow(b.size(),b.size()-1);
    cout<<hasha<<endl;
    cout<<hashb<<endl;
    cout<<"d value : "<<d<<endl;
    int x=b.size()-1;
    for(int i=b.size();i<a.size();i++)
    {
        hasha-=d*(a[i-b.size()]-'a'+1);
        hasha*=b.size();
        hasha+=a[i]-'a'+1;
        cout<<hasha<<"  ";
        if(hasha==hashb) {cout<<"the i value : "<<i<<"  "<<endl;}
    }




    return 0;
}
