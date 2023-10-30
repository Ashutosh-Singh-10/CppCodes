// #include <iostream>
// using namespace std;
// class A{
//         private:
//         int a;
//         public:
//             A(){a=0;};
//             friend class B;
//     };
// class B{
//     private:
//     int b;
//     public:
//         void showA(A& x)
//         {
//             cout<<"A::a="<<x.a;
//         }
// };
// int main()
// {
//     A apple;
//     B ball;
//     ball.showA(apple);
 

//     return 0;
// }
#include <iostream>
using namespace std;
void first(int);
int main()
{

    first(5);
    return 0;
}


void first(int a)
{
    while(a--)
    {
        cout<<a<<endl;
    }
}