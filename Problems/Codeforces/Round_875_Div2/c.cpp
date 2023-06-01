#include <bits/stdc++.h>

struct Vert {
    int v;
    int pos;
};

using namespace std;
int N = 1e5 + 10;
vector<vector<Vert>> graph(2*N);
vector<int> dist(2*N, 10*N);
vector<int> vis(2*N, 0);
int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            dist[i] = 10*N;
            vis[i] = 0;
            graph[i].clear();
        }
        for(int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            a--; 
            b--;
            Vert va = {a, i};
            Vert vb = {b, i};
            graph[a].push_back(vb);
            graph[b].push_back(va);
        }
        queue<Vert> q;
        dist[0] = 1;
        Vert ini = {0, -1};
        q.push(ini);
        
        while(!q.empty()) {
            Vert cur = q.front();
            q.pop();
            for(auto& ver : graph[cur.v]) {
                if(ver.pos > cur.pos) {
                    dist[ver.v] = min(dist[ver.v], dist[cur.v]);
                } else {
                    dist[ver.v] = min(dist[ver.v], dist[cur.v] + 1);
                }
                if(!vis[ver.v]) {
                    vis[ver.v] = 1;
                    q.push(ver);
                }   
            }
        }
        int res = 1;
        for(int i = 0; i < n; i++) {
            res = max(res, dist[i]);
        }
        cout << res << "\n";
    }
}