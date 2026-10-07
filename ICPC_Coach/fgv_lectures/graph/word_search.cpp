// Link: https://leetcode.com/problems/word-search

class Solution {
public:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n;
    int m;
    bool valid(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    
    bool dfs(int i, int j, string s, vector<vector<char>>& board) {
        if(board[i][j] != s[0]) return false;
        if(board[i][j] == s[0] && s.size() == 1) return true;
        for(int k = 0; k < 4; k++) {
            int newI = i + dir[k][0];
            int newJ = j + dir[k][1];
            if(valid(newI, newJ)) {
                char tmp = board[i][j];
                board[i][j] = '#';
                bool ok = dfs(newI, newJ, s.substr(1), board);
                if(ok) return true;
                board[i][j] = tmp;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0) return false;
        n = board.size();
        m = board[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                bool ok = dfs(i, j, word, board);
                if(ok) return true;
            }
        }
        return false;
    }
};