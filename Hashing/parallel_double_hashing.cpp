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
    int * arr1;
    int *arr2;
    int size1=7;
    int size2=11;
        hash_array(int data)
    {
        if(data<7) data=7;
        while(!isPrime(data)) data++;
        arr1 = new int[data]{0};
        size1=data;


    data++;
        while(!isPrime(data)) data++;
        arr2 = new int[data]{0};
        size2=data;
        // arr={0};
    }
      void insert(int data)
    {
        int temp=size1;
        int pos=data%size1;
        while(temp--)
        {
            if(!arr1[pos])
            {
                arr1[pos]=data;
                break;
            }
            pos=(pos+data)%size1;

            
        }
        temp=size2;
         pos=data%size2;
        while(temp--)
        {
            if(!arr2[pos])
            {
                arr2[pos]=data;
                return ;
            }
            pos=(pos+data)%size2;

            
        }
        
    }

    
pair <int ,int> search(int data)
    {
        int temp=max(size1,size2);
        int pos1=data%size1;
        int pos2=data%size2;
        pair<int ,int > positions=make_pair(-1,-1);
        while(temp--)
        {
            if((!arr1[pos1] || !arr2[pos2]) && positions.first+1 && positions.second+1) break;
            else 
            {
                if(arr1[pos1]==data && !positions.first+1)
                {
                    positions.first=pos1;
                }
                if(arr2[pos2]==data && !positions.second+1)
                {
                    positions.second =pos2;

                }
            }
            if(positions.first+1 && positions.second+1) 
            {
                // cout<<"the temp is"<<temp<<endl;
                break;
            }
            
             
            pos1=(pos1+data)%size1;
            pos2=(pos2+data)%size2;


            
        }
        // cout<<"the temp at last is"<<temp<<endl;
        return positions;

    }
    void delete_item(int data)
    {
        pair<int,int> positions=search(data);
        cout<<positions.first<<endl;
        cout<<positions.second<<endl;

    }
      void show()
    {
        
        for(int i=0;i<size1;i++)
    {
        cout<<arr1[i]<<"  ";
    }
    cout<<endl;
       for(int i=0;i<size2;i++)
    {
        cout<<arr2[i]<<"  ";
    }
    cout<<endl;
    return;
    }

};

int main()
{
    hash_array *arr=new hash_array(12);
    cout<<arr->size1<<"   "<<arr->size2<<endl;
pair <int ,int> my_pair;
    // arr->delete_item(88);
    arr->insert(12);
    arr->insert(99);
    arr->insert(25);
    my_pair=arr->search(99);
    cout<<my_pair.first<<"    "<<my_pair.second<<endl;
    arr->show();
    return 0 ;
}