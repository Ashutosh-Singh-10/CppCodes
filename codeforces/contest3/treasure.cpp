#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    long long t,temp;
    cin>>t;

    
    for(long long l=0;l<t;l++)
    {
            int n,temp;
            cin>>n;
            vector<int >vec;
            for(int i=0;i<2*n;i++)
            {
                cin>>temp;
                vec.push_back(temp);
            }
            sort(vec.begin(),vec.end());
            int x=vec[n-1]-vec[0];
            int y=vec[2*n-1]-vec[n];
            cout<<x+y<<endl;
            for(int i=0;i<n;i++)
            {
                cout<<vec[i]<<" "<<vec[i+n]<<endl;
            }
      
    }
    return 0;

}