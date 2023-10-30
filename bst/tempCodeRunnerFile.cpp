   info right;
    if(root==NULL)
    {
        left.node=NULL;     left.max_element=INT_MIN;    left.min_element=INT_MIN;  left.isbst=1; left.height=0;
     return left;   
    }
    
    left=largest_bst(root->left);
    right=largest_bst(root->right);

        if(left.isbst==1 && right.isbst==1)
        {
            if(root->data >left.max_element && root->data < right.min_element)
            {
                left.node=root;
                left.height=max(left.height,right.height)+1;
                left.max_element=max(max(left.max_element,right.max_element),root->data);
                left.min_element=min(min(left.min_element,right.min_element),root->data);
                return left;
            }

        }
        left.isbst=0;
        right.isbst=0;
       if(left.height >right.height)
       {
        return left;
       }
       return right;
       


        





}