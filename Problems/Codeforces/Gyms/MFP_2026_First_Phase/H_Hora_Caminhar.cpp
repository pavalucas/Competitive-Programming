#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXN = 2*1e5+10;
const int MOD = 1e9 + 7;

class Edge {
public:
    int from;
    int to;
    int weight;

    Edge(int from = 0, int to = 0, int weight = 1)
        : from(from), to(to), weight(weight) {}
};

class Node {
public:
    int id;
    vector<Edge> edges;

    Node(int id = 0) : id(id) {}

    void addEdge(int to, int weight = 1) {
        edges.emplace_back(id, to, weight);
    }
};

// for each node u, size of the subtree rooted at u
vector<int> sz(MAXN, 0);
vector<int> visited(MAXN, 0);
// for each edge e, number of paths that use e
vector<ll> numPath(MAXN, 0);
// for each node u, parent of u
vector<int> parent(MAXN, -1);
vector<Node> graph(MAXN, Node());

void dfs(int u, int p) {
    visited[u] = 1;
    sz[u] = 1;
    for(auto& ed : graph[u].edges) {
        if(visited[ed.to] == 0) {
            dfs(ed.to, u);
            parent[ed.to] = u;
        } 
        if(ed.to != p) {
            sz[u] += sz[ed.to];
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<Edge> edges;
    for(int i = 0; i < n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        graph[a].addEdge(b, c);
        graph[b].addEdge(a, c);
        edges.push_back(Edge(a, b, c));
    }

    dfs(0, -1);

    ll allSum = 0;
    for(int i = 0; i < n-1; i++) {
        int from = edges[i].from;
        int to = edges[i].to;
        int w = edges[i].weight;
        if(parent[from] == to) to = from;
        numPath[i] = ((ll) sz[to] * (n - sz[to])) % MOD;
        allSum = (allSum + (numPath[i] * w) % MOD) % MOD;
    }

    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        ll lastContrib = (numPath[a] * edges[a].weight) % MOD;
        ll newContrib = (numPath[a] * b) % MOD;
        allSum = ((allSum - lastContrib) % MOD + MOD) % MOD;
        allSum = (allSum + newContrib) % MOD;
        edges[a].weight = b;
        cout << allSum << endl;
    }

    return 0;
}
