class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        for (int i = 0; i < n >> 1; i++)
            for (int j = i; j < n - 1 - i; j++) {
                swap(mat[i][j], mat[j][n - 1 - i]);
                swap(mat[i][j], mat[n - 1 - i][n - 1 - j]);
                swap(mat[i][j], mat[n - 1 - j][i]);
            }
    }
};