        #include <bits/stdc++.h>
        using namespace std;
       

void fun();
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        fun();
    }
    return 0;
}
void fun()
{   
    long long n,x;
    cin>>x>>n;
    if(n==1)
    {
        cout<<x<<endl;
        return ;
    }
    long long el=2;
    long long ans=1;
    while(el*el<=x)
    {
        if(x%el==0)
        {
            if(x/el>=n)
            {
                ans=max(ans,el);
            }
            if(el>=n)
            {
                ans=max(ans,x/el);
            }

        }
     
        el++;

    }
    cout<<ans<<endl;

  
}

    