



#include <bits/stdc++.h>

using namespace std;


class Solution{
public:


	long long maxProduct(vector<int> arr, int n) {
    long long neg_product=1;
    long long pos_product=1;
    long long ans=INT_MIN;

    for(int i=0;i<n;i++)
    {
   
     
     
        pos_product*=arr[i];
        neg_product*=arr[n-i-1];
               if(ans<pos_product) ans=pos_product;
        if (ans<neg_product) ans=neg_product;
        if(pos_product==0)
        {

            pos_product=1;
        }
        if (neg_product==0) 
        {

            neg_product=1;
        }
        
        
    
  
        
    }

    return ans;
    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends