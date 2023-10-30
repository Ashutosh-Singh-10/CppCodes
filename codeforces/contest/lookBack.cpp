#include <bits/stdc++.h>
using namespace std;
int check(string & s,string &prev)
{
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!=prev[i])
        {
            if(s[i]>prev[i])
            {
                return 0;
            }
            else
            {
                // s.push_back('0');
                return 1;
            }
        }

    }
    
    return 0;

}
int main()
{
    int t,k,sz,ans,sum;
    cin>>t;
    
    
    for(int l=0;l<t;l++)
    {

        int n ,num;
        cin>>n;
        string s;
        string prev="";
        int x;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>num;
            s="";
            x=0;
            while(num!=0)
            {
                s.push_back('0'+(num%2?1:0));
                num/=2;
            }
            reverse(s.begin(),s.end());




            cout<<"))))"<<s;
            if(s.length()<=prev.length())
            {
                cout<<"?";
                x=check(s,prev);
                cout<<x;
            }
            while(s.length()<prev.length())
            {
                ans++;
                s.push_back('0');
            }
            if(x)
            {
                ans++;
                s.push_back('0');
            }
            
            prev=s;
            cout<<"      "<<prev<<endl;

            
            

        }
        cout<<"########";
        cout<<ans<<endl;



    }
    // 1 5 11 2 15 7 10
    return 0;

}