// } Driver Code Ends

/* A binary tree Node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// Function to return the level order traversal line by line of a tree.
vector<vector<int>> levelOrder(Node *node)
{
    queue<Node *> q;
    vector<int> v;
    vector<vector<int>> ans;
    q.push(node);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();
            v.push_back(curr->data);
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        ans.push_back(v);
        v.clear();
    }
    return ans;
}
