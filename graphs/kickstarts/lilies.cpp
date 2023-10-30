#include <bits/stdc++.h>
using namespace std;



int main()
{
    int T,L,ans,best_ans;

    int note=0;
    int lily=0;
    int div;
    int remainder;
    cin>>T;

    for(int cases=0;cases<T;cases++)
    {
        best_ans=INT_MAX;
        ans=0;
        note=0;
        lily=0;
        cin>>L;
        if(L<=12)
        {
            best_ans=L;
            goto there;
        }
       
        while(L)
        {
            if(ans)
            {
            div=L/lily;
            remainder=L%lily;
            if(ans+(div*2)+remainder+4<best_ans)
            {
              
                best_ans=ans+(div*2)+remainder+4;
            }
            }
            
            if(lily*2<=L && lily>=12)
            {
                L-=lily;
                lily*=2;
                ans+=6;
                note=lily;

            }
           
            else
            {
                lily+=1;
                ans+=1;
                L-=1;
                
            }

        }
        if(ans<best_ans)
        {
            best_ans=ans;
        }







        there:
        cout<<"Case #"<<cases+1<<": "<<best_ans<<endl;


    }


    return 0;
}