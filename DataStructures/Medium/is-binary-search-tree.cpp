/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/

    bool isTree = true;

    int getMax(Node* root)
    {
        if (!root)
        {
            return -1;
        }
        
        if (!root->left && !root->right)
        {
            return root->data;
        }
        
        int l = getMax(root->left);
        int r = getMax(root->right);
        
        if ((root->left && root->data <= l) || (root->right && root->data >= r))
        {
            isTree = false;
        }
        if (l >= r && l >= root->data) return l;
        if (r >= l && r >= root->data) return r;
        return root->data;
    }

    int getMin(Node* root)
    {
        if (!root)
        {
            return -1;
        }
        
        if (!root->left && !root->right)
        {
            return root->data;
        }
        
        int l = getMin(root->left);
        int r = getMin(root->right);
        
        if ((root->left && root->data <= l) || (root->right && root->data >= r))
        {
            isTree = false;
        }
        if (l <= r && l <= root->data) return l;
        if (r <= l && r <= root->data) return r;
        return root->data;
    }

	bool checkBST(Node* root) {
		getMax(root);
        getMin(root);
        return isTree;
	}
