// // #include <iostream>
// // using namespace std;
// // class Solution {
// //   public:
// //     int getMinDiff(int arr[], int n, int k) {
// //         int temp_arr[n];
// //         for(int i=0;i<n;i++)
// //         {
// //             temp_arr[i]=0;
// //         }
     
// //         int min_index=0;
// //         int max_index=0;
// //         int min=0;
// //         int max=0;
// //         for(int i=0;i<n;i++)
// //         {
// //             if(max<arr[i])
// //             {
// //                 max=arr[i];
// //                 max_index=i;
// //             }     
// //             else if(min>arr[i])
// //             {
// //                 min=arr[i];
// //                 min_index=i;
// //             }

// //         }
// //         int mid=(max+min)/2;
// //         for(int i=0;i<n;i++)
// //         {
// //             if(arr[i]>mid)
// //             {
// //                 arr[i]-=k;
// //                 temp_arr[i]=-1;
// //             }
// //             else 
// //             {
// //                 arr[i]+=k;
// //                 temp_arr[i]=1;
// //             }
// //         }
// //         point:
// //         max=arr[0];
// //         min=arr[0];
// //          for(int i=0;i<n;i++)
// //         {
// //             if(max<arr[i])
// //             {
// //                 max=arr[i];
// //                 max_index=i;
// //             }     
// //             else if(min>arr[i])
// //             {
// //                 min=arr[i];
// //                 min_index=i;
// //             }

// //         }

// //         if(temp_arr[max_index]==-1 && temp_arr[min_index]==1)
// //         {
// //             for(int i=0;i<n;i++)
// //             {
// //                 cout<<arr[i]<<"   "<<temp_arr[i]<<endl;
// //             }
// //             cout<<max<<endl;
// //             cout<<min<<endl;
            
// //             return max-min;
// //         }
// //         else
// //         {
// //             if(temp_arr[max_index]==1)
// //             {
// //                 temp_arr[max_index]==-1;
// //                 arr[max_index]-=2*k;
// //             }
// //             if(temp_arr[min_index]==-1)
// //             {
// //                 temp_arr[min_index]==1;
// //                 arr[min_index]+=2*k;
// //             }
// //             goto point;
// //         }
        
// //     }
// // };
// // int main()
// // {
// //     int arr[]={1,5,8,10};
// //     Solution obj;
// //     int ans=obj.getMinDiff(arr,4,2);
// //     cout<<ans<<endl;
// //     return 0;
// // }
// #include <iostream>
// using namespace std;

// int majorityElement(int a[], int size)
// {
        
//    int temp_arr[size+1];
//         for(int i=0;i<size+1;i++)
//         {
//             temp_arr[i]=0;
//         }
//         for(int i=0;i<size;i++)
//         {
//             temp_arr[a[i]]++;
//         }
//         for(int i=0;i<size+1;i++)
//         {
//             if(temp_arr[i]>(size/2))
//             return i;
//         }
//         return -1;
        
// }
// int main()
// {
//     int arrr[]={1,13};
//     int ans=majorityElement(arrr,2);
//     cout<<ans;
//     return 0;

// }
#include <iostream>
using namespace std;
void print_arr(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }
    
}
long long trappingWater(int arr[], int n){
        int max=arr[0];
        int temp_arr[n];
        int amount=0;
        int remember;
        for(int i=0;i<n;i++)
        {
            remember=i;
            i--;
            if(max>arr[remember])
            while(arr[remember]>temp_arr[i] )
            {
                amount+=arr[remember]-temp_arr[i];
                temp_arr[i]=arr[remember];
                i--;
            }
            else
                while(arr[remember]>temp_arr[i] )
                {
                    amount+=max-temp_arr[i];
                    temp_arr[i]=max;
                    i--;
                }
            i=remember;
            temp_arr[i]=arr[i];
        }
        return amount;
    }
int main()
{
    int arr[]={8,0,2,4,5,5,9};
    int ans=trappingWater(arr,7);
    cout<<ans;
    return 0;

}