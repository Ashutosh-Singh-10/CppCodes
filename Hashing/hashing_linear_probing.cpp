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
    int *arr;
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
        int index=data%size;
        int temp=index-1;
        
        while(index!=temp)
        {
            index=index%size;
            if(arr[index]==0 || arr[index]==-1)
            {
                arr[index]=data;
                return ;

            }
            index++;
        }
        return ;

    }
    int  search(int data)
    {
          int index=data%size;
        int temp=index-1;
        
        while(index!=temp)
        {
            if(arr[index]==0) return -1;
            if(arr[index]==data)
            {
              return index;

            }
            index++;
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
    hash_array *arr =new hash_array(7);
    // arr->show();
    arr->insert(5);
    arr->insert(40);
    arr->insert(4);
    arr->insert(33);
    arr->insert(88);
    arr->insert(80);
    arr->insert(4);

    arr->delete_element(40);
    arr->insert(47);
    arr->show();

    
    return 0;
}