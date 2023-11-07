#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    long long t,temp;
    cin>>t;

    
    for(long long l=0;l<t;l++)
    {
        int n;
        cin>>n;
        string s;
        vector<int> red,blue;
        cin>>s;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            red.push_back(temp);
        }
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            blue.push_back(temp);
        }
        int rodd=0;
        // int blue=0;
        int reven=0;
        int temp1,temp2;
        for(int i=0;i<n;i++)
        {
            temp1=rodd;
            temp2=reven;
            if(s[i]=='0')
            {


                    reven=max(temp1+red[i]-1,max(temp2+red[i],temp2+blue[i]));
                    rodd+=blue[i];
            }
            else
            {
                rodd=max(temp2+red[i],max(temp1+red[i],temp1+blue[i]));
                    reven+=blue[i];

            }




            
        }
        cout<<"#########";
        cout<<max(reven,rodd)<<endl;






    }
    return 0;

}