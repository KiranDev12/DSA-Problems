/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int sum = 0;
    void inorder(TreeNode *root, bool isLeft)
    {
        if (root == NULL)
            return;
        inorder(root->left, true);
        if (root->left == NULL && root->right == NULL && isLeft == true)
            sum += (root->val);
        inorder(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        inorder(root, false);
        return sum;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();