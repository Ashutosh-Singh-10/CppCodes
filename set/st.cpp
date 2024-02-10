#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<int> st;
    st.insert(0);
    st.insert(2);
    st.insert(5);
    st.insert(5);
    st.insert(7);
    st.insert(9);
    auto start=st.lower_bound(2);
    auto end=st.lower_bound(9);
    if(st.lower_bound(10)==st.upper_bound(20))
    cout<<"ho gya";
    while(start!=end)
    {
        cout<<*start<<"  ";
        start++;
    }
    // auto it=st.lower_bound(-3);
    // auto end=st.end();
    // if(end==it)
    // {
    //     cout<<"ye bhi theek h ";
    // }
    // cout<<*it;
    return 0;
}