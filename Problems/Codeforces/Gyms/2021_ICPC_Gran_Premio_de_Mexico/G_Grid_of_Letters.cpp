#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y;
    char letter;
};

bool check_boundary(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int flood_fill(vector<string>& grid, int x, int y) {
    int n = grid.size();
    int m = grid[0].size();
    int max_dist = 0;
    // x, y and path length
    queue<tuple<int, int, int, char>> q;
    q.push({x, y, 1, grid[x][y]});
    grid[x][y] = 'A' - 2; // Mark as visited
    while (!q.empty()) {
        auto [cx, cy, dist, letter] = q.front();
        max_dist = max(max_dist, dist);
        q.pop();
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue;
                int nx = cx + dx;
                int ny = cy + dy;
                if (check_boundary(nx, ny, n, m) && grid[nx][ny] == letter + 1) {
                    q.push({nx, ny, dist + 1, grid[nx][ny]});
                    grid[nx][ny] = 'A' - 2; // Mark as visited
                }
            }
        }
    }
    return max_dist;
    
   
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    vector<Node> nodes;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            nodes.push_back({i, j, grid[i][j]});
        }
    }
    sort(nodes.begin(), nodes.end(), [](const Node& a, const Node& b) {
        return a.letter < b.letter;
    });
    int max_count = 0;
    for (const auto& node : nodes) {
        if (grid[node.x][node.y] == node.letter) {
            int count = flood_fill(grid, node.x, node.y);
            max_count = max(max_count, count);  
        }
    }
    cout << max_count << endl;
    
    return 0;
}