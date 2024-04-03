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
    bool helper(TreeNode *L, TreeNode *R)
    {
        if (L == NULL and R == NULL)
            return 1;
        else if (L == NULL or R == NULL)
            return 0;
        if (L->val == R->val)
        {
            return (helper(L->left, R->right) && helper(L->right, R->left));
        }
        return false;
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        return helper(root->left, root->right);
    }
};