#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, fiber, microwave;
};

using ll = long long;
const ll INF = 1e18;
vector<vector<Edge>> adj(1e5 + 10);

ll dijkstra(int source, int target, int k) {
    vector<vector<ll>> dist(adj.size(), vector<ll>(k + 1, INF));

    using State = tuple<ll, int, int>;
    priority_queue<State, vector<State>, greater<State>> pq;

    dist[source][0] = 0;
    pq.emplace(0, source, 0);

    while (!pq.empty()) {
        auto [d, u, used_k] = pq.top();
        pq.pop();

        if (d != dist[u][used_k]) continue;
        if (u == target) return d;

        for (const Edge& e : adj[u]) {
            ll next_dist = d + e.fiber;
            if (next_dist < dist[e.to][used_k]) {
                dist[e.to][used_k] = next_dist;
                pq.emplace(next_dist, e.to, used_k);
            }

            if (e.microwave != -1 && used_k < k) {
                next_dist = d + e.microwave;
                if (next_dist < dist[e.to][used_k + 1]) {
                    dist[e.to][used_k + 1] = next_dist;
                    pq.emplace(next_dist, e.to, used_k + 1);
                }
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    
    for (int i = 0; i < m; ++i) {
        int u, v, f, w;
        cin >> u >> v >> f >> w;
        adj[u].push_back({v, f, w});
        adj[v].push_back({u, f, w});
    }

    cout << dijkstra(1, n, k) << endl;
}
