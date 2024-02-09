// Given a binary tree with n nodes, determine whether all the leaf nodes are at the same level or not. Return true if all leaf nodes are at the same level, and false otherwise. 

class Solution
{
public:
    /*You are required to complete this method*/
    set<int> s;
    bool check(Node *root, int l = 0)
    {

        if (root == NULL)
            return true;
        if (!root->left && !root->right)
            s.insert(l);

        check(root->left, l + 1);
        check(root->right, l + 1);

        return s.size() == 1;
    }
};