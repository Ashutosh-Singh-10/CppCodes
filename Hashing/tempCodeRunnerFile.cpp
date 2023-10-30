void delete_element(int data)
    {
        int index=search(data);
        if(index+1)
        {
            arr[index]=-1;
        }
        
 
        return ;

    }