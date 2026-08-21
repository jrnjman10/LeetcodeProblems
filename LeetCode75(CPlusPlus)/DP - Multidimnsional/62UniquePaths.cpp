class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(2,vector<int>(n, 1));
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                v[i & 1][j] = v[i & 1][j-1] + v[i-1 & 1][j];
            }
        }
        return v[m-1 & 1][n-1];
    }
};