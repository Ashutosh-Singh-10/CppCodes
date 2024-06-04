

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
using namespace std;
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, 
less<T>, rb_tree_tag,tree_order_statistics_node_update>;


int main()
{


    ordered_set <int> a;
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(5);
    a.insert(7);
    cout << *a.find_by_order(0) << endl; //output is 5
    cout << *a.find_by_order(1) << endl; //output is 5
    cout << *a.find_by_order(2) << endl; //output is 5
    cout << *a.find_by_order(3) << endl; //output is 5
    cout << *a.find_by_order(4) << endl; //output is 5
    cout<<endl;
    // cout << *a.find_by_order(5) << endl; //output is 5
    cout << (a.order_of_key(10)) << endl; //output is 5
    cout << (a.order_of_key(1)) << endl; //output is 5
    cout << (a.order_of_key(2)) << endl; //output is 5
    cout << (a.order_of_key(6)) << endl; //output is 5
    cout << (a.order_of_key(7)) << endl; //output is 5
    // cout << (a.order_of_key(10)) << endl; //output is 5

        return 0;
        


}
// #include<bits/stdc++.h>

// using namespace std;











// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #include<iostream>
// // Set
// //Can use pair of integer where .second can be index of array where .first was originally present
// template <class T> using Ordered_set = tree<T, null_type, 
// less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// // Syntax
// // Ordered_set <pair<int,int> > a; or Ordered_set<int> a;

// // Multiset
// // Not recommended Can have unwanted behaviour 
// // template <class T> using multi_ordered_set = tree<T, null_type,
// // less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

// int main() {
//     // Ordered_set<int> b;
//     // b.insert(10);
//     // cout<<b.size();
//     Ordered_set<pair<int,int>> a;

//     a.insert({1,0});
//     a.insert({1,0});
//     a.insert({7,12});
//     a.insert({9,112});
//     a.insert({12,0});
//     a.insert({17,78});
//     a.insert({17,40});
//     a.insert({112,22});
//     // cout<<a.size();
    
//     cout<<__builtin_popcount(15);
    
//     // cout << (a.find_by_order(2))->first<<" "<<(a.find_by_order(2))->second << endl; //output is 9 112
//     // cout << (a.find_by_order(5))->first<<" "<<(a.find_by_order(5))->second << endl; //output is 17 78
//     // cout << (a.order_of_key({10,12})) << endl; //output is 3
//     // cout << (a.order_of_key({12,0})) << endl; //output is 3
//     // cout << (a.order_of_key({12,1})) << endl; //output is 4
//     // cout<<a.lower_bound({17,0})->first<<"  "<<a.lower_bound({17,0})->second;
// }





