#include <iostream>
using namespace std;
class student{
    public:
    string name;
    int age;
    student()
    {
        cout<<"Constructor is called"<<endl;
    }
    student(student &pre)
    {
        name=pre.name;
        age=pre.age;
        cout<<"Inheritance has happened"<<endl;
    }
    student (string x,int y)
    {
        name=x;
        age=y;
        cout<<"Parametric constructor has been calles";
    }
};
int main()
{
    student a;
    a.name="Ashutosh Singh";
    a.age=19;
    student b(a);
    student c("Ashutosh Singh",19);


    
    return 0;

}