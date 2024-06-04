#include<bits/stdc++.h>
using namespace std;


long long sparseFun(long long a,long long b)
{

    return a+b;
}
class SparseTable{
    public:
    long long max_size=2;
    vector<vector<long long>>table;
    SparseTable(vector<long long> &vec)
    {
        long long n =vec.size();
        long long t=n;
        while(t) {t>>=1;max_size++;}
        table.resize(n, vector<long long>(max_size, -1)); 

        for(int i=0;i<n;i++) table[i][0]=vec[i];

        for(int i=1;i<max_size;i++)
        {
            long long k=1<<(i-1);
            for(int node=n-1;node>=0;node--)
            {
                if(node+k<n) 
                table[node][i]= sparseFun(  table[node][i-1],table[node+k][i-1]);
            }

        }
    }
    long long msb(long long tot)
    {
        long long x=0;
        while(tot)
        {
            x++;
            tot>>=1;
        }
        return x;
    }
    long long query(long long l, long long r)
    {
        long long tot=r-l+1;
        long long ans=0;

        while(tot )
        {
            
            long long x=msb(tot);
            long long num=1<<(x-1);
            ans=sparseFun(ans,table[l][x-1]);
            l+=num;
            tot=tot^num;

        }
        return ans;

    }


};

int main()
{

    // vector<long long> vec={1,2,3,4,5,6,7,8,9,10,11};
    // SparseTable *sp=new SparseTable(vec);
    // for(auto &i:sp->table)
    // {
    //     for(auto &j:i)
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<sp->query(1,3);
    vector<long long> arr;
    long long n,k;cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        long long t;
        cin>>t;
        arr.push_back(t);

    }

    SparseTable *sp=new SparseTable(arr);
    for(int i=0;i<k;i++)
    {
        long long l,r;
        cin>>l>>r;
        cout<<sp->query(l-1,r-1)<<"\n";
    }
    
  

    return 0 ;
}

