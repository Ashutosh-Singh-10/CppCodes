#include <bits/stdc++.h>
using namespace std;
class avl{
    public :
    int key;
    avl * left=NULL;
    avl * right=NULL;
    int height;
    avl(int data)
    {
        this->key=data;
        // cout<<this;
        height=0;
    }   
    void set_height()
    {
        if(left==NULL && right==NULL) height=0;
        else if(left==NULL) height=right->height+1;
        else if(right==NULL) height=left->height+1;
        else height=max(left->height,right->height) +1;
    }
    int  height_diff(){
        if(left==NULL && right==NULL) return 0;
        else if (left==NULL) return right->height+1;
        else if(right==NULL) return -left->height-1;
        else return right->height-left->height; 
    }
    void left_rotation()
    {
        if(right->height_diff()<0)
        {
            right->right_rotation();
        }
        int temp_key=key;
        key=right->key;
        right->key=temp_key;
        avl * temp=right->right;
        right->right=right->left;
        right->left=left;
        left=right;
        right=temp;
        left->set_height();
        set_height();
    }
    void right_rotation()
    {
        if(left->height_diff()>0)
        {
            left->left_rotation();
        }
         int temp_key=key;
        key=left->key;
        left->key=temp_key;


        avl * temp=left->left;
        left->left=left->right;
        left->right=right;
        right=left;
        left=temp;
        right->set_height();
        set_height();
        
    }
    
};
void insert(int data,avl * my_avl)


{
    if(data<my_avl->key)
    {
        if(my_avl->left==NULL)
        {
            my_avl->left=new avl(data);
            if(my_avl->right==NULL)
            my_avl->height=1;
            return ;
        }
        insert(data,my_avl->left);

    }
    else 
    {
        if(my_avl->right==NULL)
        {
            my_avl->right=new avl(data);
            if(my_avl->left==NULL) 
            my_avl->height=1;
            return ;
        }
        insert(data,my_avl->right);
    }
    my_avl->set_height();
    int temp=my_avl->height_diff();
    if(temp>=2) my_avl->left_rotation();
    else if(temp<=-2) my_avl->right_rotation();
return ;


}
avl* delete_node(avl * my_avl)
{   
    if(my_avl==NULL) return NULL;
   if(my_avl->right==NULL && my_avl->left==NULL) 
   {
    delete my_avl;
    return NULL;
   }
   else if(my_avl->left==NULL ) 
   {
    avl* temp=my_avl->right;
    delete my_avl;
    temp->set_height();
    return temp;
   }
   else if(my_avl->right==NULL)
   {
    avl * temp=my_avl->left;
    delete my_avl;
    temp->set_height();
   return temp;}

    avl * temp;
    avl* new_avl;
    if(my_avl->left->height<my_avl->right->height)
    {
         temp=my_avl->right;
         new_avl=new avl(0);
        new_avl->right=temp->left;
        new_avl->left=my_avl->left;

        temp->left=delete_node(new_avl);
        
    }
    else {
         temp=my_avl->left;
         new_avl=new avl(0);
        new_avl->left=temp->right;
        new_avl->right=my_avl->right;
        temp->right=delete_node(new_avl);
        
    }
    temp->set_height();
        return temp;
    }
avl* erase(int data,avl * my_avl)
{
    
    if(my_avl==NULL) return NULL ;
    
    else if(data==my_avl->key){
     
         avl * temp=delete_node(my_avl);
         if(temp==NULL) cout<<"this is empty"<<endl;
         return temp;
    }
    else if(data<my_avl->key) my_avl->left=  erase(data,my_avl->left);
    else my_avl->right= erase(data,my_avl->right);
    return my_avl;
}
void insert_many(int *arr,int n,avl * my_avl)
{
    for(int i=0;i<n;i++)
    {
        insert(arr[i],my_avl);
    }
    return ;
}
void traversal(char order,avl *my_avl,bool height=false)
{
    if(my_avl==NULL) return ;
        if(order == 'f' || order=='F' || order=='p' || order=='P') {cout<<my_avl->key<<"  "; if(height==true)  cout<<my_avl->height<<"       ";}
        traversal(order,my_avl->left,height);
        if(order=='i' || order=='I') {cout<<my_avl->key<<"  "; if(height==true) cout<<my_avl->height<<"       ";}
        traversal(order,my_avl->right,height);
        if(order=='s' || order=='S' || order=='L' || order=='l') {cout<<my_avl->key<<"  ";  if(height==true) cout<<my_avl->height<<"       ";}

    return;
}
int main()
{
    avl * my_avl=new avl(50);

    insert(25,my_avl);
    insert(10,my_avl);
    int arr[]{77,44,22,90,199,200};
    insert_many(arr,6,my_avl);
    traversal('i',my_avl,1);
      cout<<endl<<endl<<endl;
    traversal('p',my_avl,1);

    cout<<endl<<endl<<endl;
    my_avl= erase(90,my_avl);
    traversal('i',my_avl,1);
    cout<<endl<<endl<<endl;
    traversal('p',my_avl,1);

    return 0;

}