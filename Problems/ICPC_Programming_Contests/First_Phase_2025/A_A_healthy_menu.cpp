#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int mat[1001][1001];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    int ans = 0;
    for (int j = 0; j < m; j++) {
        int cur_max = -1;
        for (int i = 0; i < n; i++) {
            cur_max = max(cur_max, mat[i][j]);
        }
        ans += cur_max;
    }
    cout << ans << "\n";    
    return 0;
}