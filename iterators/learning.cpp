#include<bits/stdc++.h>
using namespace std;
int fun(set<int>::iterator &s,int x)
{
    while(x)
    {
        x--;
        s++;
    }
    cout<<(*s)<<endl;
    
}
int main()
{

    vector<int> vec={1,60,5,20,99,25,87};
    auto a=vec.begin();
    cout<<*a<<endl;
    cout<<*(a+5)<<endl;
    cout<<*a<<endl;
    a+=4;
    cout<<*a<<endl;

cout<<"VECTOR END"<<endl;
    set<int> st={1,4,9,8,11,-4,99,100};
    auto s=st.begin();
    cout<<*s<<endl;
    s++;
    cout<<*s<<endl;
    s--;
    cout<<*s<<endl;
    cout<<"SET ENDED"<<endl;
    set<int> ::iterator  t=st.begin();
    cout<<*t<<endl;
    fun(t,3);
    cout<<*t<<endl;
    // cout<<"HII";
    int bo=is_sorted(vec.begin(),vec.end());
    cout<<bo<<endl;
    cout<<"STL function test started"<<endl;
    auto ite=st.begin();
    advance(ite,5);
    cout<<*ite<<endl;





    // cout<<*(s+1)<<endl;


    //important functions
    // advance(it,3);
    // count(arr.begin(),arr.end(),5)
    // nth_element(arr.begin(),arr.begin()+5,arr.end())
    // copy(arr1, arr1+6, arr2.begin());     



// min_element
// max_element
// binary_search
// copy
// insert
// accumulate
// for_each
// find

    return 0;
}