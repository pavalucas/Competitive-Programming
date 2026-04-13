#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define vi vector<int>


vector<tuple<int, int, int>> edges;
int n, m, a, b, c;

struct UF {
    vi parent, rank;

    UF(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        iota(all(parent), 0);
    }

    int findParent(int v) {
        if (parent[v] != v) {
            parent[v] = findParent(parent[v]);
        }
        return parent[v];
    }

    bool unite(int a, int b) {
        a = findParent(a);
        b = findParent(b);

        if (a == b) return false;

        if (rank[a] < rank[b]) {
            parent[a] = b;
        } else {
            parent[b] = a;
        }

        rank[a] += (rank[a] == rank[b]);
        return true;
    }
};

void kruskal() {
    UF uf(n);
    sort(all(edges));

    for (auto &[w, u, v] : edges) {
        if (uf.unite(u, v)) {
            // edge (u, v) is part of the MST
        }
    }
}

string roadsInHackerland(int n, vector<vector<int>> roads) {

}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edges.emplace_back(c, a-1, b-1);
    }


}