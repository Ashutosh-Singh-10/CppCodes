
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, rad_cir, rad_dis, first_team, second_team;
    cin >> t;
    int temp1, temp2;
    vector<pair<int, int>> disks;
    int *arr_first;
    int *arr_second;
    int first_max=0;
    int second_max=0;
    int ans1;
    int ans2;
    int distance;
    for (int k = 0; k < t; k++)
    {
        ans1=0;
        ans2=0;
        first_max=INT_MAX;
        second_max=INT_MAX;
        cin >> rad_dis;
        cin >> rad_cir;
        distance=(rad_cir+rad_dis)*(rad_cir+rad_dis);






cin >> first_team;

        for (int i = 0; i < first_team; i++)
        {
            cin >> temp1;
            cin >> temp2;
            disks.push_back(make_pair(temp1, temp2));
        }
        arr_first = new int[first_team];
        for (int i = 0; i < first_team; i++)
        {
            arr_first[i] = disks[i].first * disks[i].first + disks[i].second * disks[i].second;
            if(arr_first[i]<first_max)
            {
                first_max=arr_first[i];
            }
        }
        disks.clear() ;

        cin>>second_team;
        for (int i = 0; i < second_team; i++)
        {
            cin >> temp1;
            cin >> temp2;
            disks.push_back(make_pair(temp1, temp2));
        }
        arr_second=new int[second_team];
 for (int i = 0; i < second_team; i++)
        {
            arr_second[i] = disks[i].first * disks[i].first + disks[i].second * disks[i].second;
            if(arr_second[i]<second_max)
            {
                second_max=arr_second[i];
            }
        }

        if(first_max<second_max)
        {
            for(int i=0;i<first_team;i++)
            {
                // cout<<"dkfjskjfls";
                if(arr_first[i]<second_max && arr_first[i]<=distance) 
                {

                    ans1++;
                }
            }

        }
        else if(second_max<first_max)
        {
              for(int i=0;i<second_team;i++)
            {
                // cout<<"nooooooooooooo";
                if(arr_second[i]<first_max && arr_second[i]<=distance)
                {
                    ans2++;
                }
            }
            
        }

cout<<"distancee  "<<distance;
// cout<<endl<<first_max<<endl;
// cout<<"dlfkjslfjlsjdflsdj"<<endl;
// for(int i=0;i<first_team;i++)
// {
//     cout<<arr_first[i]<<endl;
// }
// cout<<"dlfkjslfjlsjdflsdj"<<endl;
// cout<<endl<<second_max<<endl;
// cout<<"dlfkjslfjlsjdflsdj"<<endl;
// for(int i=0;i<second_team;i++)
// {
//     cout<<arr_second[i]<<endl;
// }
// cout<<"dlfkjslfjlsjdflsdj"<<endl;


        cout<<"Case #"<<k+1<<": "<<ans1<<" "<<ans2<<endl;




    }

    return 0;
}