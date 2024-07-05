class Solution {
private:
    vector<int> cols;
    vector<int> pos_diags;
    vector<int> neg_diags;
    int result;

public:
    int totalNQueens(int n) {
        cols.resize(n);
        pos_diags.resize(2 * n - 1);
        neg_diags.resize(2 * n - 1);

        result = 0;

        helper_function(0, n);

        return result;
    }

    void helper_function(int row_idx, int &n) {
        if (row_idx == n) {
            result++;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!cols[i] && !pos_diags[row_idx + i] && !neg_diags[row_idx - i + (n - 1)]) {
                cols[i] = 1;
                pos_diags[row_idx + i] = 1;
                neg_diags[row_idx - i + (n - 1)] = 1;

                //board[row_idx][i] = 'Q';
                
                helper_function(row_idx + 1, n);
                
                cols[i] = 0;
                pos_diags[row_idx + i] = 0;
                neg_diags[row_idx - i + (n - 1)] = 0;
                
                //board[row_idx][i] = '.';
            }
        }
    }
};

/*class Solution {
private:
    vector<int> cols;
    vector<int> pos_diags;
    vector<int> neg_diags;
    vector<vector<string>> result;

public:
    vector<vector<string>> solveNQueens(int n) {
        string row(n, '.');
        cols.resize(n);
        pos_diags.resize(2 * n - 1);
        neg_diags.resize(2 * n - 1);

        vector<string> board(n, row);
        helper_function(board, 0, n);

        return result;
    }

    void helper_function(vector<string> &board, int row_idx, int &n) {
        if (row_idx == n) {
            result.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!cols[i] && !pos_diags[row_idx + i] && !neg_diags[row_idx - i + (n - 1)]) {
                cols[i] = 1;
                pos_diags[row_idx + i] = 1;
                neg_diags[row_idx - i + (n - 1)] = 1;

                board[row_idx][i] = 'Q';
                
                helper_function(board, row_idx + 1, n);
                
                cols[i] = 0;
                pos_diags[row_idx + i] = 0;
                neg_diags[row_idx - i + (n - 1)] = 0;
                
                board[row_idx][i] = '.';
            }
        }
    }
};*/