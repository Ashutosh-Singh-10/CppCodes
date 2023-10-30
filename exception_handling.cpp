 #include <bits/stdc++.h>
 using namespace std;
 int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Your code goes here
        int count=0;
        sort(a,a+n);
        sort(b,b+m);
        int ptra=0,ptrb=0;
        while(ptra!=n || ptrb!=m)
        {
            if(a[ptra]==b[ptrb])
            {count++;
            ptra++;
            ptrb++;
            }
            else if(a[ptra]>b[ptrb])
                ptrb++;
            
            else ptra++;
        }
        return count;
        
    }
    int main()
    {
      int m,n;
      cin>>m>>n;
      int a[m],b[n];
      for(int i=0;i<m;i++)
      {
        cin>>a[i];
      }
      for(int i=0;i<n;i++)
      {
        cin>>b[i];
      }
      int result=NumberofElementsInIntersection(a,b,m,n);
      cout<<result;
      return 0;
    }
  