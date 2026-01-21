class Solution {
public:
    static const int MOD = 1e9 + 7;

    int totalWays(int n, int m, vector<vector<int>>& grid) {
        vector<vector<long long>> t(n, vector<long long>(m, -1));
        return solve(grid, n - 1, m - 1, t);
    }

    long long solve(vector<vector<int>>& grid, int i, int j,
                    vector<vector<long long>>& t) {
        if (i < 0 || j < 0) return 0;
        if (grid[i][j] == 1) return 0;
        if (i == 0 && j == 0) return 1;

        if (t[i][j] != -1) return t[i][j];

        long long up = solve(grid, i - 1, j, t);
        long long left = solve(grid, i, j - 1, t);

        return t[i][j] = (up + left) % MOD;
    }
};
