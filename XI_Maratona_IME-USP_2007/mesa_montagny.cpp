/* https://www.urionlinejudge.com.br/judge/pt/problems/view/2131 */

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define GRAY 0
#define WHITE 1
#define BLACK 2

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unsigned long long ull;

bool checkBipartide(vvi& g, int n)
{
    vi visited(n, 0);
    vi color(n, GRAY);
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            queue<int> q;
            q.push(i);
            color[i] = WHITE;
            while(!q.empty())
            {
                int v = q.front();
                q.pop();
                visited[v] = 1;
                int desiredColor = (color[v] == WHITE)? BLACK : WHITE;
                for(auto u : g[v])
                {
                    if(color[u] == GRAY)
                    {
                        color[u] = desiredColor;
                        q.push(u);
                    }
                    else if(color[u] != desiredColor)
                        return false;
                }
            }
        }
    }
    return true;
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, t = 1;
    while(cin >> n >> m)
    {
        vvi g(n);
        for(int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            a--; b--;
            g[a].pb(b);
            g[b].pb(a);
        }
        cout << "Instancia " << t++ << endl;
        if(!checkBipartide(g, n))
            cout << "nao" << endl;
        else
            cout << "sim" << endl;
        cout << endl;
    }


    return 0;
}