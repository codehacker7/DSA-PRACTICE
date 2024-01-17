class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.')); // Initialize an empty board

        solveNQueensUtil(result, board, n, 0);

        return result;
    }

private:
    bool isSafeToPlace(const vector<string>& board, int row, int col, int n) {
        // Check the column
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Check upper left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check upper right diagonal
        for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void solveNQueensUtil(vector<vector<string>>& result, vector<string>& board, int n, int row) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (isSafeToPlace(board, row, col, n)) {
                board[row][col] = 'Q';
                solveNQueensUtil(result, board, n, row + 1);
                board[row][col] = '.'; // Backtrack
            }
        }
    }
};