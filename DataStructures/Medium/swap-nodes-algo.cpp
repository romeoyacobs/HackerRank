#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the swapNodes function below.
 */

struct TreeNode
{
    TreeNode(int i) : index{i}, left{nullptr}, right{nullptr} {} 
    int index;
    TreeNode * left;
    TreeNode * right;
};

// 6 9 4 2 1 7 5 10 8 11 3
// 2 3
// 4 5
// 6 -1
// -1 7
// 8 9
// 10 11
// 12 13
// -1 14
// -1 -1
// 15 -1
// 16 17
// -1 -1
// -1 -1
// -1 -1
// -1 -1
// -1 -1
// -1 -1

void fillChild(TreeNode* head, int i, const vector<vector<int>>& indexes)
{
    queue<TreeNode*> nodes;
    nodes.push(head);
    for (int i = 0; i < indexes.size(); ++i)
    {
        // check if !empty
        TreeNode* last = nodes.front();
        nodes.pop();

        auto lvalue = indexes[i][0];
        auto rvalue = indexes[i][1];

        if (lvalue != -1)
        {
            last->left = new TreeNode(lvalue);
            nodes.push(last->left);
        }
        if (rvalue != -1)
        {
            last->right = new TreeNode(rvalue);
            nodes.push(last->right);
        }
    }
}


void inOrder(TreeNode *root, vector<int>& indexes) {
    if (root == nullptr) return;

    inOrder(root->left, indexes);
    indexes.push_back(root->index);
    inOrder(root->right, indexes);
}

void performSwap(TreeNode * &root, int level, int q)
{
    if (root == nullptr) return;

    if (level % q == 0)
    {
        TreeNode * tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }
    performSwap(root->left, level + 1, q);
    performSwap(root->right, level + 1, q);
}

vector<vector<int>> swapNodes(const vector<vector<int>>& indexes, vector<int> queries) {
    TreeNode* head = new TreeNode(1);

    fillChild(head, 0, indexes);

    vector<vector<int>> res;

    for (int q : queries)
    {
        performSwap(head, 1, q);

        vector<int> afterSwap;
        inOrder(head, afterSwap);
        res.push_back(afterSwap);
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
