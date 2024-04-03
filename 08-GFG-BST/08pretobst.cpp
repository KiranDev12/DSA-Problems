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
    // int i = 1;
    // TreeNode* helper(TreeNode* root, vector<int>& preorder) {
    //     if(i==preorder.size()) return root;
    //     if(root==NULL) return NULL;
    //     if(root->val>preorder[i]) {
    //         root->left = new TreeNode(preorder[i++]);
    //         return helper(root->left, preorder);
    //     } else {
    //         root->right = new TreeNode(preorder[i++]);
    //         return helper(root->right, preorder);
    //     }
    //     return root;
    // }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        if (preorder.size() == 0)
            return NULL;
        TreeNode *root = new TreeNode(preorder[0]);
        if (preorder.size() == 1)
            return root;
        vector<int> left;
        vector<int> right;
        for (int i = 0; i < preorder.size(); i++)
        {
            if (preorder[i] > preorder[0])
                right.push_back(preorder[i]);
            else if (preorder[i] < preorder[0])
                left.push_back(preorder[i]);
        }
        root->left = bstFromPreorder(left);
        root->right = bstFromPreorder(right);
        return root;
    }
};

// TC-Beats 100% SC-Beats 90%
class Solution
{
public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        if (preorder.size() == 0)
            return NULL;
        TreeNode *root = NULL;
        for (int i : preorder)
            root = InsertBst(root, i);
        return root;
    }

    TreeNode *InsertBst(TreeNode *root, int i)
    {
        if (!root)
            return new TreeNode(i);
        if (i < root->val)
            root->left = InsertBst(root->left, i);
        else
            root->right = InsertBst(root->right, i);
        return root;
    }
}