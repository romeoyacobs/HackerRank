/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

int height(node *n)  
{  
    if (n == nullptr) return -1;  
    return n->ht;  
} 

int BalanceFactor(node * n)
{
    if (n == nullptr) return 0;
    return height(n->left) - height(n->right);
}


node * rightTurn(node * root)
{
    node * child = root->left;
    node * grand = child->right;
    
    child->right = root;  
    root->left = grand;  
  
    root->ht = max(height(root->left), 
                    height(root->right)) + 1;  
    child->ht = max(height(child->left), 
                    height(child->right)) + 1;
    
    return child;
}

node * leftTurn(node * root)
{
    node * child = root->right;
    node * grand = child->left;
    
    child->left = root;  
    root->right = grand;  
  
    root->ht = max(height(root->left), 
                    height(root->right)) + 1;  
    child->ht = max(height(child->left), 
                    height(child->right)) + 1; 
    
    return child;
}

node * insert(node * root,int val)
{
    //cout << "In function\n";
    if (root == nullptr)
    {
        //cout << "Creating new node with " << val << "\n";
        node * n = new node;
        n->val = val;
        n->ht = 0;
        n->left = nullptr;
        n->right = nullptr;
        return n;
    }
    
	if (val < root->val)
    {
        //cout << "Going to left tree\n";
        root->left = insert(root->left, val);
    }
    else if (val > root->val)
    {
        //cout << "Going to right tree\n";
        root->right = insert(root->right, val);
    }
    else
    {
        return root;
    }
    
    auto factor = BalanceFactor(root);
    
    if (factor < -1)
    {
        if (val > root->right->val) // right right case
        {
            return leftTurn(root);
        }
        else
        {
            // right left case
            root->right = rightTurn(root->right);
            return leftTurn(root);
        }
    }
    else if (factor > 1)
    {
        if (val < root->left->val) // left left case
        {
            return rightTurn(root);
        }
        else
        {
            // left right case
            root->left = leftTurn(root->left);
            return rightTurn(root);
        }
    }
    else
    {
        if (root != nullptr)
        {
            root->ht = max(height(root->left), height(root->right)) + 1;
        }
    }
    return root;
}