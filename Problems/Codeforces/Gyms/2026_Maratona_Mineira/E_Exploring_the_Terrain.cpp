#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n, m, t;
    cin >> n >> m >> t;

    vector<vector<int>> mat(550);
    for (int i = 0; i < n; i++)
    {
        mat[i].resize(550);
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    }

    vector<vector<int>> g(300000);
    for (int i = 0; i < t; i++)
    {
        g[i].resize(2);
        cin >> g[i][0] >> g[i][1];
        g[i][0]--; g[i][1]--;
    }

    vector<vector<int>> a(300000);
    for (int i = 0; i < t; i++)
    {
        a[i].resize(2);
        cin >> a[i][0] >> a[i][1];
        a[i][0]--; a[i][1]--;
    }

    vector<vector<int>> pos = { {0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    int totalg = 0;
    int totala = 0;
    for (int i = 0; i < t; i++)
    {
        for (int p1 = 0; p1 < pos.size(); p1++)
        {
            bool ok = true;

            int gx = g[i][0] + pos[p1][0];
            int gy = g[i][1] + pos[p1][1];

            if (gx < 0 || gx >= n) continue;
            if (gy < 0 || gy >= m) continue;

            for (int p2 = 0; p2 < pos.size(); p2++)
            {
                int ax = a[i][0] + pos[p2][0];
                int ay = a[i][1] + pos[p2][1];

                if (ax < 0 || ax >= n) continue;
                if (ay < 0 || ay >= m) continue;

                if (gx == ax && gy == ay)
                {
                    ok = false;
                    break;
                }
            }

            if (ok)
            {
                totalg += mat[gx][gy];
                mat[gx][gy] = 0;
            }
        }

        for (int p2 = 0; p2 < pos.size(); p2++)
        {
            bool ok = true;

            int ax = a[i][0] + pos[p2][0];
            int ay = a[i][1] + pos[p2][1];

            if (ax < 0 || ax >= n) continue;
            if (ay < 0 || ay >= m) continue;

            for (int p1 = 0; p1 < pos.size(); p1++)
            {
                int gx = g[i][0] + pos[p1][0];
                int gy = g[i][1] + pos[p1][1];

                if (gx < 0 || gx >= n) continue;
                if (gy < 0 || gy >= m) continue;

                if (gx == ax && gy == ay)
                {
                    ok = false;
                    break;
                }
            }

            if (ok)
            {
                // cout << "ok" << endl;
                totala += mat[ax][ay];
                mat[ax][ay] = 0;
            }
        }

    }

    cout << totalg << ' ' << totala << endl;

    return 0;
}
