#include <iostream>
using namespace std;
int myFuntion(int x)
{
    return x+5;
}
double myFuntion(double x)
{
    return x+8;
}

int main()
{
    int a=myFuntion(5);
    double b=myFuntion(5.0);
    cout<<a<<"  "<<b<<endl;
    return 0;
}