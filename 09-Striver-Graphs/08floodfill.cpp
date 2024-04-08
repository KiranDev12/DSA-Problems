class Solution
{
public:
    void helper(vector<vector<int>> &image, int r, int c, int m, int n, int target, int color)
    {
        if (r < 0 || c < 0 || r == m || c == n || image[r][c] == color ||
            image[r][c] != target)
            return;
        image[r][c] = color;
        helper(image, r + 1, c, m, n, target, color);
        helper(image, r - 1, c, m, n, target, color);
        helper(image, r, c + 1, m, n, target, color);
        helper(image, r, c - 1, m, n, target, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        helper(image, sr, sc, image.size(), image[0].size(), image[sr][sc], color);
        return image;
    }
};
auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();