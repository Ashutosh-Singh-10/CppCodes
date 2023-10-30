#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{

    if (n <= 1)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

class hash_array
{

    public:
    int * arr;
    int size=7;
        hash_array(int data)
    {
        if(data<7) data=7;
        while(!isPrime(data)) data++;
        arr = new int[data]{0};
        size=data;
        // arr={0};
    }
    void insert(int data)
    {
        int temp=size;
        int pos=data%size;
        while(temp--)
        {
            if(!arr[pos])
            {
                arr[pos]=data;
                return ;
            }
            pos=(pos+data)%size;

            
        }
        
    }
    int search(int data)
    {
        int temp=size;
        int pos=data%size;
        while(temp--)
        {
            if(!arr[pos]) break;
            else if(arr[pos]==data) return pos;
             
            pos=(pos+data)%size;

            
        }
        return -1;

    }
    void delete_element(int data)
    {
        int index=search(data);
        if(index+1)
        {
            arr[index]=-1;
        }
        
 
        return ;

    }
    void show()
    {
        
        for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<"  ";
    }
    return;
    }


};
int main()
{
    hash_array *arr=new hash_array(7);
    cout<<arr->size<<endl;
    arr->insert(12);
    arr->insert(24);
    arr->insert(23);
    arr->insert(34);
    arr->insert(45);
    arr->insert(56);
    arr->insert(67);
    arr->insert(78);
    cout<<arr->search(24)<<endl;
    arr->delete_element(12);
    arr->show();


    return 0;
}