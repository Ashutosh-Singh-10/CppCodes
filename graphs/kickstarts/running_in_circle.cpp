// Ada has decided that this year, she will take part in the annual marathon that takes place in her city. Since this is the first time she would be running such a long distance, she has decided to start practising for it by running in the circular track of length L units near her house.

// Ada wants to focus only on running, so she decides to use a machine to count the number of laps she has run. The machine is placed at the starting line of the circular track and starts the count from 0. Every time Ada arrives at the starting line running in the same direction as the last time she departed from the starting line, the machine increases the number of laps that Ada has run by 1. If she crosses the starting line or changes direction at the starting line, the machine considers the new direction as the direction she last touched the starting line. The machine only remembers the last direction in which Ada touched the starting line. During a lap, Ada can change directions any number of times, but as long as she eventually touches the starting line in the same direction as she last touched it, the count of laps in the machine increases by 1.

// This is the first time Ada has practised running long distances, so she cannot run continuously. She runs some distance, then takes a break to regain her energy. However, when she starts running again after taking a break, she cannot remember which direction she was running in previously. So she picks one of the directions, clockwise or anticlockwise, and starts running from the same position where she stopped.

// Ada begins at the starting line and is initially facing in the direction of her first run. She runs a total of N times, taking breaks in between. Given the information of the distance Di units Ada has run, and the direction Ci she has taken (clockwise or anticlockwise) when she ran the i-th time, for all i from 1,…,N, can you tell the number of laps that would be reported by the machine at the end?



#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T,N,L,ans,dist;
    cin>>T;
    int temp=0;
    char direction;
    for(int cases=1;cases<=T;cases++)
    {
        dist=0;
        ans=0;
        cin>>L;cin>>N;
        for(int i=0;i<N;i++)
        {
            cin>>temp;
            cin>>direction;
            if(direction=='C') dist+=temp;
            if(direction=='A') dist-=temp;
            if(dist>=L)
            {
                ans+=dist/L;
                dist=dist%L;
                if(dist==0)
                {
                    dist=L;
                    ans--;
                }
            }
            if(dist<=-L)
            {
                dist*=-1;
                 ans+=dist/L;
                dist=dist%L;
                dist*=-1;
                if(dist==0)
                {
                    dist=-L;
                    ans--;
                }
            }
            
        }
        cout<<"Case #"<<cases<<": "<<ans<<endl;

    }
return 0;
}