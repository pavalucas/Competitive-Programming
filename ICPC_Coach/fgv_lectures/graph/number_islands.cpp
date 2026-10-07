// Link: https://leetcode.com/problems/number-of-islands

class Solution {
public:
    int dir[4][2] = {{0,1}, {0,-1}, {1, 0}, {-1,0}};
    vector<vector<int>> visited;
    vector<vector<char>> inGrid;
    int n;
    int m;
    bool isValid(int i, int j) {
        return i < n && i >= 0 && j < m && j >= 0;
    }
    
    void dfs(int i, int j) {
        visited[i][j] = 1;
        for(int k = 0; k < 4; k++) {
            int nextI = i + dir[k][0];
            int nextJ = j + dir[k][1];
            if(isValid(nextI, nextJ) && !visited[nextI][nextJ] && inGrid[nextI][nextJ] == '1') {
                dfs(nextI, nextJ);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        int result = 0;
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        visited = vis;
        inGrid = grid;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    dfs(i, j);
                    result++;
                }
            }
        }
        return result;
    }
};