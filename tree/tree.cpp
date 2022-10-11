#include "tree.h"

Tree::Tree(T *arr, size_t n)
{
    using namespace std;

    TreeNode *nodes = new TreeNode[n];
    for (int i = 1; i < n; i++)
    {
        nodes[i].val = arr[i];
        nodes[i].left = (nodes + 2 * i);
        nodes[i].right = (nodes + 2 * i + 1);
    }
    this->root = &nodes[1];
    this->_mhead = nodes;
}

void Tree::preorder()
{
    using namespace std;

    stack<TreeNode *> stk;
    stk.push(this->root);
    while (!stk.empty())
    {
        TreeNode *top = stk.top();
        stk.pop();
        cout << top->val << ' ';
        if (top->right != nullptr)
        {
            stk.push(top->right);
        }
        if (top->left != nullptr)
        {
            stk.push(top->left);
        }
    }
    cout << endl;
}
