#include <bits/stdc++.h>
using namespace std;
class Heap{
    public:
    int index=0;
    int arr[100];
    int size=100;
  
    Heap(int data)
    {
        arr[0]=data;
        index++;
    }
    void insert(int data)
    {
        if(size==data) return ;
        arr[index]=data;
        heapify_one(index);
        index++;
        return ;
    }
    int  parent(int index)           {return (index-1)/2;}
    int left_child(int index)       {return index*2+1;}
    int right_child(int index)     {return index*2+2;}
    
    void heapify_one(int index)
    {
        while(index)
        {
            int my_parent=parent(index);
            if(arr[index]<arr[my_parent])
            {
                arr[index]=arr[index]+arr[my_parent];
                arr[my_parent]=arr[index]-arr[my_parent];
                arr[index]=arr[index]-arr[my_parent];
                index=my_parent;
            }
            else break;
            
        }
        return ;
    }
    void show()
    {
        for(int i=0;i<index;i++)
        {
            cout<<arr[i]<<"   ";
        }
        cout<<endl;
    }
    void heapify_all()
    {
        for(int i=0;i<index;i++)
        {

            heapify_one(i);
            
        }
    }
    int find(int x,int pos=0)
    {

        if(pos>index) return -1;
        if(arr[pos]==x) return pos; 
        int l=find(x,left_child(pos));
        if (l!=-1)  return l;
        return find(x,right_child(pos));
        

    }
    // void remove(int x)
    // {
    //         int pos=find(x);
    //         int exchange_pos=0;
    //         while(left_child(pos)<=index)
    //         {
    //             if(right_child(pos)<=index)
    //             {
    //                 if(arr[right_child(pos)]<arr[left_child(pos)])
    //                  exchange_pos=right_child(pos);
    //                  else exchange_pos=left_child(pos);
    //             }
    //             else exchange_pos=left_child(pos);
    //             arr[pos]=arr[exchange_pos]+arr[pos];
    //             arr[exchange_pos]=arr[pos]-arr[exchange_pos];
    //             arr[pos]=arr[pos]-arr[exchange_pos];
    //             pos=exchange_pos;

    //         }
    //           arr[pos]=arr[index-1]+arr[index-1];
    //             arr[index-1]=arr[pos]-arr[index-1];
    //             arr[pos]=arr[pos]-arr[index-1];
    //             heapify_one(index-1);
    //             heapify_one(pos);
            
            
    // }
     void remove(int x)
    {
        if(index==0) return ;
            int pos=find(x);
            cout<<pos<<endl;
            int exchange_pos=0;
            while(left_child(pos)<=index)
            {
                if(right_child(pos)<=index)
                {
                    if(arr[right_child(pos)]<arr[left_child(pos)])
                    {
                        arr[pos]=arr[right_child(pos)];
                        pos=right_child(pos);
                    }
                     else {
                        arr[pos]=arr[left_child(pos)];
                        pos=left_child(pos);
                     }
                     show();
                }
                else 
                {
                      arr[pos]=arr[left_child(pos)];
                        pos=left_child(pos);

                }
              

            }
            if(pos==index-1)
            {
                arr[index-1]=0;
                index--;
                return;
            }
                arr[pos]=arr[index-1];
                arr[index-1]=0;
                index--;
                // heapify_one(index-1);
                heapify_one(pos);
            
            
    }
};



int main()
{
     Heap *h=new Heap(7);
    int arr[]{1,4,6,11,3,8,10,34,2,0};
    for(int i=0;i<sizeof(arr)/sizeof(int);i++)
    {
        h->insert(arr[i]);
    }
    h->show();
    h->heapify_all();
    h->show();
    // cout<<h->find(34);
    cout<<endl;
    // h->remove(1);
    // h->show();


    return 0;
}