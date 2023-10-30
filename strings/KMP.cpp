#include <bits/stdc++.h>
using namespace std;
void buildLPS(string &str,vector<int> & vec)
{
    for(int i=1;i<vec.size();i++)
    {
        if(str[vec[i-1]]==str[i])
        {
            vec[i]=vec[i-1]+1;
        }
        else 
        {
            while(vec[i])
            {

            }
        }

    }

}

int main()
{

    string str="ab";
    vector<int> vec(str.size(),0);
    return 0;
}