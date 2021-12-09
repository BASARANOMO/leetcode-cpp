class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int xCnt = 0, oCnt = 0;
        for (string& row : board) {
            for (char c : row) {
                if (c == 'X') xCnt++;
                if (c == 'O') oCnt++;
            }
        }
        if (xCnt != oCnt && xCnt != oCnt + 1) return false;
        if (win(board, 'X') && xCnt != oCnt + 1) return false;
        if (win(board, 'O') && xCnt != oCnt) return false;
        return true;
    }

    bool win(vector<string>& board, char p) {
        for (int i = 0; i < 3; i++) {
            if (p == board[i][0] && p == board[i][1] && p == board[i][2]) return true;
            if (p == board[0][i] && p == board[1][i] && p == board[2][i]) return true;
        }
        if (p == board[0][0] && p == board[1][1] && p == board[2][2]) return true;
        if (p == board[0][2] && p == board[1][1] && p == board[2][0]) return true;
        return false;
    }
};