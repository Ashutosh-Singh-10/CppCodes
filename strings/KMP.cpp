#include<bits/stdc++.h>
using namespace std;
void buildLPS(string & s,vector<int> &vec)
{
    vec.push_back(0);
    for(int i=1;i<s.length();i++)
    {
        if(s[i]==s[vec[i-1]])
        {
            vec.push_back(vec[i-1]+1);

        }
        else if(vec[i-1]==0)
        {
            vec.push_back(0);

        }
        else
        {
            int temp=i-1;
            while( s[temp]!=s[i])
            {
                temp=vec[temp];
                if(temp==0) break;

            }
            if(s[vec[temp]]==s[i])
            {
                vec.push_back(temp+1);
                
            }
            else vec.push_back(0);

            
        }

    }
}
int main()
{
    string s="cabdcancacacabcabdcab";
    vector<int> vec;
    buildLPS(s,vec);
    cout<<endl;
    for(auto &i:vec) cout<<i<<"  ";
    return 0;
}