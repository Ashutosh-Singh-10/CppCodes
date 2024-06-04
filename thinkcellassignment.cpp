#include <map>
#include<bits/stdc++.h>
using namespace std;
template<typename K, typename V>
class interval_map {
	// friend void IntervalMapTest();
public:
	V m_valBegin;
	std::map<K,V> m_map;
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {

        if(!(keyBegin<keyEnd)) return;
        auto start=m_map.lower_bound(keyBegin);
        auto end=m_map.upper_bound(keyEnd);
        if(m_map.size()==0)
        {
            if(m_valBegin==val) return;
            m_map[keyBegin]=val;
            m_map[keyEnd]=m_valBegin;
            return ;

        }
        else
        {
            if(start!=end)
            {
                end--;
                m_map[keyEnd]=end->second;
            }
            if(m_map.count(keyEnd)==0)
            {
                if(start==m_map.begin())
                {

                m_map[keyEnd]=m_valBegin;
                }
                else 
                {
                    start--;
                    m_map[keyEnd]=start->second;
                }
            }
           
         auto start1=m_map.lower_bound(keyBegin);
         auto end1=m_map.lower_bound(keyEnd);
            m_map.erase(start1,end1);



            m_map[keyBegin]=val;
                  auto start2=m_map.lower_bound(keyBegin);
                  if(start2!=m_map.begin())
                  {

                    start2--;
                    while(1)
                    {
                        auto start3=m_map.lower_bound(keyBegin);
                        if(start2->second==start3->second)
                        {
                            m_map.erase(start3);
                        }
                        else break;
                    }

                  }

                  while(1)
                  {
                    
                    auto start4=m_map.lower_bound(keyBegin);
                    if(start4==m_map.end()) break;
                    auto x=start4->second;
                    start4++;
                    if(x==start4->second)
                    {
                        m_map.erase(start4);
                    }
                    else break;
                  }
                  
        

           

        }
    






// INSERT YOUR SOLUTION HERE
	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};

int main()
{
    int n;cin>>n;
    char ch='#';
    interval_map<int,char> ds(ch);
    while(n--)
    {
        int start,end;char c;
        cin>>start>>end>>c;
        ds.assign(start,end,c);

        char prev='%';
    for(auto  &i:ds.m_map)
    {
        if(i.second==prev)
        {
            cout<<"YES";
        }
        prev=i.second;
        cout<<i.first<<" "<<i.second<<" ";
    }
    // cout<<"**"<<n;
    cout<<endl;
    }
    


    
    return 0;
}

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.











