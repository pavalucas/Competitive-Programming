#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> adj(m);
    for (int i = 0; i < m; i++)
        adj[i].resize(m, 1000);

    vector<vector<int>> langs(n);
    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;

        langs[i].resize(l);
        for (int j = 0; j < l; j++)
        {
            cin >> langs[i][j];
            langs[i][j]--;
        }

        for (int j = 0; j < l; j++)
            for (int k = 0; k < l; k++)
                adj[langs[i][j]][langs[i][k]] = adj[langs[i][k]][langs[i][j]] = 1;
    }

    for (int i = 0; i < m; i++)
        adj[i][i] = 0;

    for (int k = 0; k < m; k++)
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                if (adj[i][k] + adj[k][j] < adj[i][j])
                    adj[i][j] = adj[i][k] + adj[k][j];

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        int total = 1000;
        for (int l1: langs[a])
            for (int l2: langs[b])
                if (total > adj[l1][l2])
                    total = adj[l1][l2];

        if (total == 1000)
            cout << -1 << endl;
        else
            cout << total << endl;
    }

    return 0;
}
