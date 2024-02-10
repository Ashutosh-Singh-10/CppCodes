#include<bits/stdc++.h>
using namespace std;
int construct(vector<int> &vec,vector<int> & tree,int curr,int l,int r)
{
    if(l==r)
    {
        tree[curr]=vec[l];
        return tree[curr];
    }
    int mid=(l+r)/2;
    int left=construct(vec,tree,(curr)*2+1,l,mid);
    int right=construct(vec,tree,(curr)*2+2,mid+1,r);
    tree[curr]=left+right;
    return tree[curr];

}

int getSum(vector<int> &tree,int curr,int x,int y,int l,int r)
{
    if(l==x && r==y)
    {

        return tree[curr];
    }
    else if(l>y  || x>r) return 0;
    int mid=(l+r)/2;
   int left= getSum(tree,curr*2+1,        x,min(y,mid),             l,mid);

    int right=getSum(tree,curr*2+2,       max(mid+1,x),y,           mid+1,r);               
    return left+right;
}
void update(vector<int> &tree,int curr,int l,int r,int nw,int newValue)
{
    if(l==r)
    {
        tree[curr]=newValue;
        return ;
    }
    int mid=(l+r)/2;
    if(nw<=mid)
    {
        update(tree,curr*2+1,l,mid,nw,newValue);
    }
    else update(tree,curr*2+2,mid+1,r,nw,newValue);

    tree[curr]=tree[curr*2+1]+tree[curr*2+2];
}
int main()
{
    vector<int> vec={10,5,7,8,22,99,11,100,3};
    int n=vec.size();
        vector<int> tree(4*n,0);
        construct(vec,tree,0,0,n-1);
        for(auto &i:tree)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<accumulate(vec.begin(),vec.end(),0)<<endl;;
        cout<<getSum(tree,0,2,5,0,n-1)<<endl;
        update(tree,0,0,n-1,3,-10);
        // cout<<accumulate(vec.begin(),vec.end(),0)<<endl;;
        cout<<tree[0]<<endl;
        for(auto &i:tree)
        {
            cout<<i<<" ";
        }   
        cout<<endl;



        cout<<"HII";
        



    
    
    return 0 ;
}