/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 */

// @lc code=start
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        List<List<Integer>> lst = new ArrayList<>();
        if (root == null)
        {
            return lst;
        }

        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        boolean reverseLevel = false;

        while (!q.isEmpty())
        {
            int size = q.size();
            List<Integer> sub = new ArrayList<>();

            for (int i = 0; i < size; i++)
            {
                TreeNode curr = q.remove();
                sub.add(curr.val);

                if (curr.left != null)
                {
                    q.add(curr.left);
                }
                if (curr.right != null)
                {
                    q.add(curr.right);
                }
            }

            if (reverseLevel)
            {
                Collections.reverse(sub);
            }

            lst.add(sub);
            reverseLevel = !reverseLevel;
        }
        return lst;
    }
};
// @lc code=end
