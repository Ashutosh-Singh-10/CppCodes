#include<bits/stdc++.h>
using namespace std;

long long operation(long long a,long long  b)
{      
    return a+b;
    // return a^b;
    // return min(a,b);
    // return max(a,b);
}
long long updateOperation(long long l,long long r,long long val,long long prev)
{
    return ((r-l+1)*val)+prev;
    // if((r-l+1)%2==1) return val;return 0;
    // return val;
    // return (r-l+1)*val;
}
long long downOperation(long long newValue,long long prevValue)
{
    return newValue + prevValue;

}
long long getSum(vector<long long> &tree,vector<long long> &copy,long long curr,long long x,long long y,long long l,long long r,long long notPossible,long long defaultVal)
{
    if(l==x && r==y)
    {
            if(copy[curr]!=notPossible) 
            return updateOperation(l,r,copy[curr],tree[curr]);  
            return tree[curr];
    }
    else if(l>y  || x>r)
    {
        return defaultVal;
    } 
    


    if(copy[curr]!=notPossible)
    {
        long long val=copy[curr];
        tree[curr]=updateOperation(l,r,copy[curr],tree[curr]);
        if(l!=r)
        {
            if(copy[curr*2+1]==notPossible)
            copy[curr*2+1]=val;
            else copy[curr*2+1]= downOperation(val,copy[curr*2+1]);

            if(copy[curr*2+2]==notPossible)
            copy[curr*2+2]=val;
            else copy[curr*2+2]= downOperation(val,copy[curr*2+2]);
            // copy[curr*2+2]=val;
        }
    }
    copy[curr]=notPossible;

    long long mid=l+(r-l)/2;
    long long left= getSum(tree,copy,curr*2+1,        x,min(y,mid),             l,mid,notPossible, defaultVal);
    long long right=getSum(tree,copy,curr*2+2,       max(mid+1,x),y,           mid+1,r,notPossible, defaultVal);                   
    return operation(left,right);
}
long long update(vector<long long> &tree,vector<long long> &copy,long long curr,long long x,long long y,long long l,long long r,long long newVal,long long notPossible)
{
    if(l==x && r==y)
    {
            if(copy[curr]==notPossible)
             copy[curr]=newVal;  
            else
            copy[curr]=downOperation(copy[curr],newVal);

            return updateOperation(l,r,newVal,tree[curr]);
    }
    else if(l>y  || x>r) 
    {
        if(copy[curr]!=notPossible)
        return updateOperation(l,r,copy[curr],tree[curr]);
        return tree[curr];
    }
    
    if(l==r)
    {
        tree[curr]=newVal;
        copy[curr]=notPossible;
        return tree[curr];
    }
    long long mid=l+(r-l)/2;
    long long left= update(tree,copy,curr*2+1,        x,min(y,mid),             l,mid,newVal,notPossible);
    long long right=update(tree,copy,curr*2+2,       max(mid+1,x),y,           mid+1,r,newVal,notPossible);                   

    tree[curr]=operation(left,right);
    copy[curr]=notPossible;
    return tree[curr];
}
long long construct(vector<long long> &vec,vector<long long> & tree,long long curr,long long l,long long r,long long el)
{
    while(curr+5>=tree.size())
    {
        tree.push_back(el);
    }
    if(l==r)
    {
        tree[curr]=vec[l];
        return tree[curr];
    }
    long long mid=l+(r-l)/2;
    long long left=construct(vec,tree,(curr)*2+1,l,mid,el);
    long long right=construct(vec,tree,(curr)*2+2,mid+1,r,el);
    tree[curr]=operation(left,right);

    
    return tree[curr];

}
class SegTree{
    public:
    vector<long long> tree;
    vector<long long> copy;
    long long n=0;
    long long lazy=0;
    long long el=0;
    long long defaultVal=0;
    long long notPossible=LONG_LONG_MIN;
    SegTree(vector<long long> &vec,long long Lazy=0)
    {
        lazy=Lazy;
        n=vec.size();
        construct(vec,tree,0,0,vec.size()-1,el);
        for(long long i=0;i<tree.size();i++)
        {
            copy.push_back(notPossible);
        }
    }
    long long query(long long l,long long r)
    {
        return getSum(tree,copy,0,l,r,0,n-1,notPossible, defaultVal);
    }
    long long change(long long l,long long r,long long newVal)
    {
        return update(tree,copy,0,l,r,0,n-1,newVal,notPossible);
    }

};
int main()
{

    long long n,q,t;
    cin>>n>>q;
    vector<long long> arr;  
    for(long long i=0;i<n;i++)
    {
        cin>>t;
        arr.push_back(t);
    }
    auto root=new SegTree(arr);
        // for(auto &i:root->tree)cout<<i<<" ";        cout<<endl;
        // for(auto &i:root->copy)cout<<i<<" ";        cout<<endl;
    for(long long i=0;i<q;i++)
    {
        // for(auto &i:root->tree)cout<<i<<" ";        cout<<endl;
        // for(auto &i:root->copy)cout<<i<<" ";        cout<<endl;
        long long a,b,c;
        cin>>c;
        // cin>>c>>a>>b;    
        // cin>>a>>b;
        
        if(c==1)
        {
            cin>>a>>b>>c;
            a--;
            b--;
            root->change(a,b,c);
        // for(auto &i:root->tree)cout<<i<<" ";        cout<<endl;
        // for(auto &i:root->copy)cout<<i<<" ";        cout<<endl;

        }
        else 
        {
            cin>>a;
            a--;
            cout<<root->query(a,a)<<endl;;
            // cout<<root->query(a+1,a+1)<<endl;;
            // cout<<root->query(a-1,a-1)<<endl;;
            // cout<<root->query(a+2,a+2)<<endl;;
        }
        
    }
    return 0;
    // vector<long long> vec={10,5,7,8,22,99,11,100,3};
    // int n=vec.size();
    // auto root=new SegTree(vec);

    // for(auto &i:root->tree)cout<<i<<" ";        cout<<endl;
    // for(auto &i:root->copy)cout<<i<<" ";        cout<<endl;
    // cout<<root->change(3,7,8)<<endl;
    // for(auto &i:root->tree)cout<<i<<" ";        cout<<endl;
    // for(auto &i:root->copy)cout<<i<<" ";        cout<<endl;
    // root->change(3,7,8);









    return 0;
}