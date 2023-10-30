#include <bits/stdc++.h>
using namespace std;
bool ispar(string x)
    {
        stack<char> st;
       for(auto i:x)
       {
           cout<<i;
          
           if(i=='(' || i=='[' || i=='{')
           {
               st.push(i);
           }
           
           else if(st.empty())
           {
           cout<<"change";
           return false;}
           else if(( (i==')' && st.top()=='(' ) || (i==']' && st.top()=='[') || (i=='}' && st.top()==']') ))
           st.pop();
           else
           {cout<<"NO";
           return false;}
           
            
    //    cout<<i;
        
       }
       if(st.empty())
       return true;
       cout<<"false";
       return false;
    }

int main()
{
    string st = "[([]{})]";
    bool k = ispar(st);
    cout << "The result is "<<k;
    return 0;
}