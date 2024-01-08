/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        List<List<Integer>> result = new ArrayList<>();

        if (root == null)
        {
            return result;
        }

        Queue<TreeNode> queue = new LinkedList<>(); // Size of the queue is the number of elements in that level.
        queue.offer(root);

        while (!queue.isEmpty())
        {
            int levelSize = queue.size();
            List<Integer> currentLevel = new ArrayList<>();
            for (int i = 0; i < levelSize; i++)
            {
                TreeNode currentNode = queue.poll();
                currentLevel.add(currentNode.val);
                if (currentNode.left != null)
                {
                    queue.offer(currentNode.left);
                }
                if (currentNode.right != null)
                {
                    queue.offer(currentNode.right);
                }
            }
            result.add(0, currentLevel);
        }
        return result;
    }
};
// @lc code=end
