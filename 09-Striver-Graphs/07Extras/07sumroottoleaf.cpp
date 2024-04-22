class Solution
{
public:
    int traverse(TreeNode *root, int sum)
    {
        if (root == NULL)
            return 0;
        sum = sum * 10 + root->val;
        if (root->left == NULL && root->right == NULL)
        {
            // leaf node ke case mei
            return sum;
        }
        return traverse(root->left, sum) + traverse(root->right, sum);
    }
    int sumNumbers(TreeNode *root)
    {
        return traverse(root, 0);
    }
};
auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
