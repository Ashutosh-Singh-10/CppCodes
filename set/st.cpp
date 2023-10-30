#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<int> st;
    st.insert(0);
    st.insert(2);
    st.insert(5);
    auto it=st.lower_bound(-3);
    auto end=st.end();
    if(end==it)
    {
        cout<<"ye bhi theek h ";
    }
    cout<<*it;
    return 0;
}