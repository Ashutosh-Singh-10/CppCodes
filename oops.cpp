// #include <iostream>
// using namespace std;
// class student
// {
//     public:
//     string name;
//     int age;
//     student()
//     {
//         cout<<"default constructor";
//     }
//     student(student &pre)
//     {
//         name=pre.name;
//         age=pre.age;
//     }
//     ~student()
//     {
//         cout<<"destructor"<<endl;
//     }
//     bool operator / (student a)
//     {
//         cout<<endl<<name<<"   "<<a.name<<"  "<<age<<"  "<<a.age<<endl;
//         if(name==a.name && age==a.age) return true;

//         return false;
//     }
//     void printInfo()
//     {
//         cout<<endl<<name<<" is "<<age<<" year old";
//     }
// };
// int main()
// {
//     student a;
//     a.name="Ashutosh Singh";
//     a.age=19;
//     student b;
//     b.name="Ashutosh Singh";
//     b.age=19;
//     a.printInfo();
//     b.printInfo();
//     if(a/b)    cout<<"   equal";
//     else cout<<"  Not Equal";

//     return 0;


// }
#include <iostream>
using namespace std;
int main()
{
    int i=1;
    int sum=0;
    sum=++i + ++i + ++i+ ++i;
  
    cout<<sum;

}