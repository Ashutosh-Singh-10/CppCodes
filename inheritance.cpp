// #include <iostream>
// using namespace std;
// class a{
//     private: //can only access in the same class
//     int c=500;
//         void printB1()
//         {
//             cout<<"private of b";
//         }
//     protected:   // can only be access inside the function and in inside derived class
//         int b=10;
//         void printB2()
//         {
//             cout<<"Protected of b";

//         }
//     public:  // can be access anywhere
//         void printB3()
//         {
//             cout<<"Public of b";
//         }
//         void change()
//         {   
//             cout<<endl<<c<<endl;
//             c=10000;
//             cout<<b<<endl;
//             b=50;
//             cout<<b<<endl;
//             cout<<c;
//         }
// };

// int main()
// {

//     a any;
//     any.printB3();
//     any.change();
//     return 0;
// }
    
#include <iostream>
using namespace std;
class parents
{
    public:
    void display()
    {
        cout<<"winter is coming"<<endl;
    }
};
class child:public parents
{
    public:
    void display()
    {
        cout<<"Lannister always pays their debt";
    }
};
int main()
{
    class child a;
    a.display();
    return 0;
}