// //{ Driver Code Starts
// #include<bits/stdc++.h>
// using namespace std;


// // } Driver Code Ends
// // Function to return minimum number of jumps to end of array

// class Solution{
//   public:
//     int minJumps(int arr[], int n){
//         int step_available=arr[0];
//         int ans=1;
//         int next_step=0;
//         if(n==1) return 0;
//         if(!step_available) return -1;
//         for(int i=1;i<n-1;i++)
//         {
            

//                 if(next_step<arr[i])
//                 {
//                     next_step=arr[i];
                
//                 }
//                 else
//                 {
//                     next_step--;
//                 }
//                 step_available--;

//             if(!next_step) return -1;
//             if(step_available==0)
//             {
                
//                 step_available=next_step;
//                 ans++;
//             }
            
//         }
//         return ans;

//     }
    
// };


// //{ Driver Code Starts.

// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n,i,j;
//         cin>>n;
//         int arr[n];
//         for(int i=0; i<n; i++)
//             cin>>arr[i];
//         Solution obj;
//         cout<<obj.minJumps(arr, n)<<endl;
//     }
//     return 0;
// }

// // } Driver Code Ends



//{ Driver Code Starts























































//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int find_maximum(int arr[],int num)
    {
        int curr_max=arr[0];
        int ans=arr[0];
        // int sum=arr[0];
        int index=0;
        // int neg_index=0;
        for(int i=1;i<num;i++)
        {
            
            // if(i<0) neg_index=i;
            if(curr_max<0)
            {
                index=0;
                curr_max=0;

              
                
                
            }
            index++;
            curr_max+=arr[i];
            // sum+=arr[i];
            if(curr_max>ans) ans=curr_max;
            cout<<curr_max<<endl;
        }
        for(int i=0;i<num-index;i++)
        {  if(curr_max<0)
            {
                
                curr_max=0;

              
                
                
            }
            
            curr_max+=arr[i];
            // sum+=arr[i];
            if(curr_max>ans) ans=curr_max;
            cout<<"   "<<curr_max<<endl;
            
        }
        // for(int i=0;i<neg_index;i++)
        // {
        //     if (curr_max<0) curr_max=0;
        //     curr_max+=arr[i];
        //     if(curr_max>ans) ans=curr_max;
            
        // }
        // cout<<neg_index;
        return ans;
        
    }
    int circularSubarraySum(int arr[], int num){
        int start=0;
        int end=0;
        int curr_max=arr[0];
        int ans=arr[0];
        int allsum=arr[0];
        for(int i=1;i<num;i++)
        { if(curr_max<0)
            {
                
                curr_max=0;
                end=i;
            }
            allsum+=arr[i];
            curr_max+=arr[i];
            if(curr_max>ans) ans=curr_max;
            // cout<<curr_max<<endl;
        }
        // cout<<"the value of end is"<<endl;
        cout<<"the value of end is "<<end<<endl;
        for(int i=0;i<num;i++)
        {
            cout<<"   "<<curr_max;
            
            
             curr_max+=arr[i];
                   cout<<"   "<<curr_max<<endl;
            there:
            if(end>=num-1 ) break;
            if(arr[end]<0)
            {
                // cout<<"hey";
                end++;
                if(end>=num-1 ) break;
                curr_max-=arr[end];
                 
                 cout<<"iside"<<curr_max<<endl;

                goto there;
                
            }
            
            if(i>=end) 
            {  
                 end++;
                curr_max-=arr[i];
                goto there;
            }       
            
            if(curr_max>ans) ans=curr_max;
            if(curr_max<0)
            {
                break;
            }
            
            
        }
        
        
        
        // int ans=find_maximum(arr,num);
      
        return ans;
    
    }
};

//{ Driver Code Starts.

int main()
 {
	int T=1;
	
	//testcases
	// cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends