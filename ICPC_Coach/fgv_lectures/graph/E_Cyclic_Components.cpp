#include <bits/stdc++.h>

using namespace std;

vector<int> vis(200010, 0);
vector<vector<int>> gra(200010);
bool cycle = true;

void dfs(int v) {
    vis[v] = 1;
    if(gra[v].size() != 2) cycle = false;
    for(int at : gra[v]) {
        if(!vis[at]) {
            dfs(at);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        gra[a].push_back(b);
        gra[b].push_back(a);
    }

    int resp = 0;
    for(int i = 0; i < m; i++) {
        if(!vis[i]) {
            cycle = true;
            dfs(i);
            if(cycle) resp++;
        }
    }
    cout << resp << endl;

    return 0;
}