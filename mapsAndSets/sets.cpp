#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<int> st;
    for(int i=0;i<16;i+=2)
    {
        st.insert(i);
        
    }
    st.insert(2);
    st.insert(2);
    st.insert(2);
    for(auto &i:st) cout<<i<<"  ";cout<<endl;
    cout<<st.count(2)<<endl;
    cout<<*st.upper_bound(2)<<endl;
    cout<<*st.lower_bound(2)<<endl;
    cout<<*st.upper_bound(11)<<endl;
    cout<<*st.lower_bound(11)<<endl;
    cout<<*st.upper_bound(-10)<<endl;
    cout<<*st.lower_bound(-10)<<endl;
    cout<<*st.upper_bound(20)<<endl;
    cout<<*st.lower_bound(20)<<endl;
    cout<<*st.end()<<endl;
    // cout<<*(st.begin()+2)<<endl;
    

    
    
    return 0;
}