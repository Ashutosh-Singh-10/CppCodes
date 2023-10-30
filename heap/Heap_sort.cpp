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
        heapify_one_min(index);
        index++;
        return ;
    }
    int  parent(int index)           {return (index-1)/2;}
    int left_child(int index)       {return index*2+1;}
    int right_child(int index)     {return index*2+2;}
    
    void heapify_one_min(int index)
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
       void heapify_one_max(int index)
    {
        while(index)
        {
            int my_parent=parent(index);
            if(arr[index]>arr[my_parent])
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
    void heapify_min()
    {
        for(int i=0;i<index;i++)
        {

            heapify_one_min(i);
            
        }
    }
       void heapify_max()
    {
        for(int i=0;i<index;i++)
        {

            heapify_one_max(i);
            
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
                heapify_one_min(pos);
            
            
    }
    void heapify_max_down(int target,int pos)
    {
        while(target<pos ) 
        {
            // show();
            if(left_child(target)>pos) return ;
            else if(right_child(target)>pos) 
            {
                cout<<"second"<<endl;
                int left=left_child(target);
                if(arr[target]<arr[left])
                {
                arr[target]=arr[left]+arr[target];
                arr[left]=arr[target]-arr[left];
                arr[target]=arr[target]-arr[left];
                target=left;
                }
                else return ;
            }
            else
            {
                // cout<<"third"<<endl;
                int replace;
                if(arr[left_child(target)]>arr[right_child(target)])
                {
                    replace=left_child(target);
                }
                else replace=right_child(target);
                if(arr[target]<arr[replace])
                {
                    arr[target]=arr[target]+arr[replace];
                    arr[replace]=arr[target]-arr[replace];
                    arr[target]=arr[target]-arr[replace];
                    target=replace;
                }
                else return ;

            }
        }
        return ;
        
        
    }
    void Heap_sort()
    {
        int pos=index;
        while(--pos)
        {
            cout<<pos<<endl;
            arr[0]=arr[pos]+arr[0];
            arr[pos]=arr[0]-arr[pos];
            arr[0]=arr[0]-arr[pos];
            show();
            heapify_max_down(0,pos-1);
        }        
        
        
    }
};


int main()
{
       Heap *h=new Heap(7);
    int arr[]{2,4,5,2,6,9,3,1};
       for(int i=0;i<sizeof(arr)/sizeof(int);i++)
    {
        h->insert(arr[i]);
    }
    h->show();
    // h->heapify_max_down(0,h->index-1);
    h->heapify_max();
    h->show();


    cout<<endl<<endl;
    h->Heap_sort();
    h->show();

     return 0; 
}