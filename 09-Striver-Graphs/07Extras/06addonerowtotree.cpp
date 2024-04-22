/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        queue<TreeNode *> q;
        q.push(root);
        int level = 1;
        while (!q.empty())
        {
            int size = q.size();
            if (level == (depth - 1))
            {
                for (int i = 0; i < size; i++)
                {
                    TreeNode *curr = q.front();
                    q.pop();
                    TreeNode *leftCurr = curr->left;
                    TreeNode *rightCurr = curr->right;
                    curr->left = new TreeNode(val);
                    curr->right = new TreeNode(val);
                    curr->left->left = leftCurr;
                    curr->right->right = rightCurr;
                }
                return root;
            }
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            level++;
        }
        return root;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();