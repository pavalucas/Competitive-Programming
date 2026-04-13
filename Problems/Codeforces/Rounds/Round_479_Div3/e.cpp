#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rp(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)

#define TRACE(x...)
#define PRINT(x...)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl )

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;

vi vis(200010, 0);
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
    rp(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        gra[a].pb(b);
        gra[b].pb(a);
    }

    int resp = 0;
    rp(i,n) {
        if(!vis[i]) {
            cycle = true;
            dfs(i);
            if(cycle) resp++;
        }
    }
    cout << resp << endl;

    return 0;
}
