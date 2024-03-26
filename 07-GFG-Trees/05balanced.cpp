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

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

auto __untie_cin = cin.tie(nullptr);
auto __unsync_ios_stdio = ios_base::sync_with_stdio(false);
class Solution
{
public:
    int depth(TreeNode *root)
    {
        if (!root)
            return 0;
        int leftDepth = depth(root->left);
        if (leftDepth == -1)
            return -1;

        int rightHeight = depth(root->right);
        if (rightHeight == -1)
            return -1;

        if (!(abs(leftDepth - rightHeight) <= 1))
            return -1;
        return max(leftDepth, rightHeight) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        return depth(root) != -1;
    }
};