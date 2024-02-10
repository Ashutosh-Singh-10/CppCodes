#include<bits/stdc++.h>
using namespace std;
#define ll long long
void buildLPS(string &s,vector<ll> &vec)
{
    if(vec.size()!=s.length())
    {
        vec=new vector(s.length(),0);
    }
      for(ll i=1;i<s.length();i++)
        {
            ll curr=vec[i-1];
            while(curr && s[i]!=s[curr])
            {
                curr=vec[curr-1];
            }
            if(s[i]==s[curr])
            {
                vec[i]=curr+1;
            }
          

        }

}
int main()
{


    
    return ;
}