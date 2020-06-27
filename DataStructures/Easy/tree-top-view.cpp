#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    map<int, pair<int, int>> mp; // maps horisontal distance to pair [level, data]

    void topViewParse(Node * root, int horDist, int level) {
        if (root == nullptr) return;

        auto it = mp.find(horDist);
        if (it == mp.end() || it->second.first > level)
        {
            mp[horDist] = make_pair(level, root->data);
        }

        topViewParse(root->left, horDist - 1, level + 1);
        topViewParse(root->right, horDist + 1, level + 1);
    }

    void topView(Node * root) {
        if (root == nullptr) return;

        topViewParse(root, 0, 0);

        for (const auto& el : mp)
        {
            cout << el.second.second << " ";
        }
    }
    //1 2 4 14 23 37 108 111 115 116 83 84 85
}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.topView(root);
    return 0;
}
