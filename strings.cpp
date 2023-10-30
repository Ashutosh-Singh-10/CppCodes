#include <iostream>
#include<algorithm>
#include <string>
using namespace std;
int main()
{
    // string str;
    // string str1(5,'n');
    // string str2="Singh";
    // getline(cin,str);
    
    // str.append(str2);
    // cout<<str<<endl;
    // string str3=str+str2;
    // cout<<str3;
    // string abc="Ashutosh";
    // abc.clear();
    // if(abc.empty())
    // {
    //     cout<<"string is empty"<<endl;
    // }
    // cout<<abc<<endl;
    // abc="Ashutosh";
    // string abc2="Ashutosh";
    // if(!abc.compare(abc2)) cout<<"strings are equal"<<endl;
    // cout<<abc2.compare(abc)<<endl;
    // abc.erase(4,4);
    // cout<<abc<<endl;
    // cout<<abc.find("hu")<<endl;


    // string s1="nincompoop";
    // s1.insert(3,"lol");
    // cout<<s1<<endl;
    // cout<<s1.size()<<endl;
    // for(int i=0;i<s1.length();i++)
    // {
    //     cout<<s1[i]<<endl;
    // }
    // string s=s1.substr(6,4);
    // cout<<s<<endl;

    // string a="244";
    // int b=stoi(a);
    // cout<<b<<endl;
    // b=333;
    // a.append(to_string(b));
    // cout<<a<<endl;


    // sort(a.begin(),a.end());
    // cout<<a<<endl;

    // string lstr="slfjlaskjd";
    // transform(lstr.begin(),lstr.end(),lstr.begin(),::toupper);
    // cout<<lstr<<endl;

    //problems

    // string s="56629522095";
    // sort(s.begin(),s.end(),greater<int>());
    // cout<<s<<endl;

    string str="abcdbbbbbacbb";
    int arr[26];
    for(int j=0;j<26;j++)
    {
        arr[j]=0;
    }
    for(int i=0;i<str.length();i++)
    {
        arr[str[i]-65]+=1;
    }
    char ans='a';
    int maxf=0;
    for (int i=0;i<26;i++)
    {
        if(arr[i]>maxf)
        {
            ans='a'+i;
            maxf=arr[i];
        }
    }
    cout<<'a'+ans<<endl;
    

    


    return 0;
}