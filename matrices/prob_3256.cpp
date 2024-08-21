class Solution {
private:
    long long dp[101][101][101][3];

    int n, m;
    
    long long solve(int idx, int a, int b, int count, vector<vector<pair<int, int>>> &board) {
        if(count == 3)
            return 0;

        if(idx >= n)
            return -1e16;

        if(dp[idx][a][b][count] != -1)
            return dp[idx][a][b][count];

        long long res = -1e16;

        for(auto it : board[idx]) {
            int val = it.first, k = it.second;

            if(k != a && k != b) {
                if(a == 100)
                    res = max(res, solve(idx + 1, k, b, count + 1, board) + val);

                else if(b == 100)
                    res = max(res, solve(idx + 1, a, k, count + 1, board) + val);

                else
                    res = max(res, solve(idx + 1, a, b, count + 1, board) + val);
            }
        }

        res = max(res, solve(idx + 1, a, b, count, board));

        return dp[idx][a][b][count] = res;
    }

public:
    long long maximumValueSum(vector<vector<int>>& board) {
        n = board.size(), m = board[0].size();

        vector<vector<pair<int, int>>> max_board(n);
        vector<pair<int, int>> temp;

        for(int i = 0; i < n; i++) {
            temp.resize(0);
            for(int j = 0; j < m; j++) 
                temp.push_back({board[i][j], j});

            sort(temp.begin(), temp.end());
            for(int j = 0; j < 3; j++) 
                max_board[i].push_back(temp[m - 1 - j]);
        }

        memset(dp, -1, sizeof(dp));
        return solve(0, 100, 100, 0, max_board);
    }
};