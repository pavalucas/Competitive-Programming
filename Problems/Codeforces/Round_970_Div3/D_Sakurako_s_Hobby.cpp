#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> g(2e5 + 10);
vector<int> visited(2e5 + 10, 0);
vector<int> color(2e5 + 10, 0);
vector<int> cc(2e5 + 10, 0);
vector<int> cc_to_black(2e5 + 10, 0);

void dfs(int u, int num_cc) {
    visited[u] = 1;
    cc[u] = num_cc;
    cc_to_black[num_cc] += (1 - color[u]);
    for(auto v : g[u]) {
        if(!visited[v]) {
            dfs(v, num_cc);
        }
    }
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        visited.assign(n, 0);
        cc_to_black.assign(n, 0);
        for(int i = 0; i < n; i++) {
            g[i].clear();
            int p;
            cin >> p;
            p--;
            if(i != p)
                g[i].push_back(p);
        }
        string s;
        cin >> s;
        for(int i = 0; i < n; i++) {
            color[i] = s[i] - '0';
        }
        int num_cc = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(i, num_cc);
                num_cc++;
            }
        }
        for(int i = 0; i < n; i++) {
            cout << cc_to_black[cc[i]] << " ";
        }
        cout << endl;
        
    }
    return 0;
}