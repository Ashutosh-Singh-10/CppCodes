#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s="aabbaa";    
       vector<int> vec(s.length(),0);
        
        for(int i=1;i<s.length();i++)
        {
            int curr=vec[i-1];
            while(curr && s[i]!=s[curr])
            {
                curr=vec[curr-1];
            }
            if(s[i]==s[curr])
            {
                vec[i]=curr+1;
            }
          

        }

        for(auto &i:vec) cout<<i<<" ";
    string big="aabbaabbaa";
    int x=0;
    int ans=0;
    for(int i=0;i<big.length();i++)
    {

        while(x && big[i]!=s[x])
        {
            x=vec[x-1];
        }
        if(s[x]==big[i])
        {
            x++;
        }
        
        
        if(x==s.length())
        {
            ans++;
            x=vec[s.length()-1];
        }
        cout<<x<<endl;

    }
    cout<<endl<<"The ans is ->";
    cout<<ans<<endl;
    

    return 0;   
}   