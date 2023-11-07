#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   
         unordered_map<ll,ll> ones;
         unordered_map<ll,ll> two;
         unordered_map<ll,ll> three;
         unordered_map<ll,ll> four;
         unordered_map<ll,ll> five;

         ll n;
         cin>>n;
         string s;
         vector<vector<string>> vec(6);
         ll ans=0;
         for(ll i=0;i<n;i++)
         {
            cin>>s;
            vec[s.length()].push_back(s);
         }
         ll cnt=0;
         for(auto &i:vec[1])
         {
            cnt=0;
            for(auto &j:i)
            {
                cnt+=j-'0';
            }
            ones[cnt]++;
         }
         for(auto &i:vec[2])
         {
            cnt=0;
            for(auto &j:i)
            {
                cnt+=j-'0';
            }
            two[cnt]++;
         }
         for(auto &i:vec[3])
         {
            cnt=0;
            ll x=i[0]-'0';
            ll y=i[1]-'0';
            y+=i[2]-'0';
            if(ones.count(y-x))
            {
                ans+=ones[y-x];
            }
            x+=i[1]-'0';
            y-=i[1]-'0';
            if(ones.count(x-y))
            {
                ans+=ones[x-y];
            }
           
            three[y+x]++;
         }
         for(auto &i:vec[4])
         {
            
            ll x=i[0]-'0';
            ll y=i[1]-'0';
            y+=i[2]-'0';
            y+=i[3]-'0';
            if(two.count(y-x))
            {
                ans+=two[y-x];
            }


            x+=i[1]-'0';
            x+=i[2]-'0';

            y-=i[1]-'0';
            y-=i[2]-'0';
            if(two.count(x-y))
            {
                ans+=two[x-y];
            }
           
            four[y+x]++;
         }
         for(auto &i:vec[5])
         {
            
            ll x=i[0]-'0';

            ll mid=i[1]-'0';
            ll y=i[3]-'0';
            y+=i[4]-'0';
            y+=i[2]-'0';
            if(three.count(y+mid-x))
            {
                ans+=three[y+mid-x];
            }            
            if(ones.count(y-mid-x))
            {
                ans+=ones[y-mid-x];
            }

            x+=mid+i[2]-'0';
            mid=i[3]-'0';
            y=i[4]-'0';



            if(three.count(x+mid-y))
            {
                ans+=three[x+mid-y];
            }            
            if(ones.count(x-mid-y))
            {
                ans+=ones[x-mid-y];
            }




           
            five[y+mid+x]++;
         }


        //  cout<<ans<<endl;

         for(auto &i:ones)
         {
            ll x=i.second;
            if(x>1)
        ans+=x*(x-1);
         }
         for(auto &i:two)
         {
            ll x=i.second;
            if(x>1)
            ans+=x*(x-1);

         }
         for(auto &i:three)
         {
            ll x=i.second;
            if(x>1)
            ans+=x*(x-1);

         }
         for(auto &i:four)
         {
            ll x=i.second;
            if(x>1)
            ans+=x*(x-1);

         }
         for(auto &i:five)
         {
            ll x=i.second;
            if(x>1)
            ans+=x*(x-1);

         }
         ans+=n;
    cout<<ans<<endl;    
    // cout<<ones.size();
    // cout<<two.size();
    // cout<<three.size();
    // cout<<four.size();
    // cout<<five.size();
        


      
    
    return 0;

}