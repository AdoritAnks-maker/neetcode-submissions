class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> mpp;

        int rows = 9;
        while (rows--) {
            mpp.clear();
            for (int j = 0; j < 9; j++) {
                if (board[rows][j] == '.') continue;

                if (mpp.find(board[rows][j]) != mpp.end()) {
                    return false;
                }
                mpp[board[rows][j]]++;
            }
        }

        int cols = 9;
        while (cols--) {
            mpp.clear();
            for (int i = 0; i < 9; i++) {
                if (board[i][cols] == '.') continue;

                if (mpp.find(board[i][cols]) != mpp.end()) {
                    return false;
                }
                mpp[board[i][cols]]++;
            }
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                mpp.clear();

                for (int rows = i; rows < i + 3; rows++) {
                    for (int cols = j; cols < j + 3; cols++) {
                        if (board[rows][cols] == '.') continue;

                        if (mpp.find(board[rows][cols]) != mpp.end()) {
                            return false;
                        }

                        mpp[board[rows][cols]]++;
                    }
                }
            }
        }

        return true;
    }
};