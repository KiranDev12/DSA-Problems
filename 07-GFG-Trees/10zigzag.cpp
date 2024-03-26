/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(NULLptr), right(NULLptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        bool reverseLevel = false;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> sub;

            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                sub.push_back(curr->val);

                if (curr->left != NULL)
                {
                    q.push(curr->left);
                }
                if (curr->right != NULL)
                {
                    q.push(curr->right);
                }
            }

            if (reverseLevel)
            {
                reverse(sub.begin(), sub.end());
            }

            ans.push_back(sub);
            reverseLevel = !reverseLevel;
        }
        return ans;
    }
};