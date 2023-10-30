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
class Hash_array
{
    public:

    vector<int> *arr;
    int size = 7;
    Hash_array()
    {

    }
    Hash_array(int data)
    {
        if (data < 7)
            data = 7;
        while (!isPrime(data))
        {
            data++;
        }
        size = data;
        arr = new vector<int>[data];
    }
    void insert(int data)
    {
        int index=data%size;
        arr[index].push_back(data);
    }
    int search(int data)
    {
        int index=data%size;
        for(int i =0;i<arr[index].size();i++)
        {
            if(arr[index][i]==data)
            {
                return i;
            }
        }
        return -1;
    }
    void delete_element(int data)
    {
        int index=data%size;
        int sub_index=search(data);
        if(!sub_index+1)
        {
            arr[index].erase(arr[index].begin()+sub_index);
        }
        return ;
    }
    void show()
    {
        cout<<endl;
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<arr[i].size();j++)
            {
                cout<<arr[i][j]<<" ";
                if(j==arr[i].size()-1) cout<<endl;
            }
            
        }
    }

};

int main()
{

    Hash_array *arr;
    arr=new Hash_array(18);
    cout<<arr->size;
    arr->insert(5);
    arr->insert(9);
    arr->insert(49);
    arr->insert(33);
    arr->insert(30);
   arr->delete_element(9);
   arr->show();
   
 


    return 0;
}