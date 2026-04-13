#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rp(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep(i, x, n) for (int i = (x); i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)

#define TRACE(x...)
#define WATCH(x) TRACE( cout << #x" = " << x << endl)
#define PRINT(x) TRACE(printf(x))
#define WATCHR(a, b) TRACE( for(auto c = a; c != b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end()); } )

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;

vector<pair<int, int> > resp;
int n, m;

bool transformB(vector<vector<int> >& matA) {
    vector<vector<int> > matB(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matA[i][j] == 1 && i < n - 1 && j < m - 1 && matA[i+1][j] == 1 && matA[i][j+1] == 1 && matA[i+1][j+1] == 1) {
                matB[i][j] = 1;
                matB[i+1][j] = 1;
                matB[i][j+1] = 1;
                matB[i+1][j+1] = 1;
                resp.push_back(mp(i+1, j+1));
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matA[i][j] != matB[i][j]) return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    vector<vector<int> > matA(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matA[i][j];
        }
    }

    bool valid = transformB(matA);
    if(!valid) cout << -1 << endl;
    else {
        cout << resp.size() << endl;
        for(auto p : resp) {
            cout << p.fi << " " << p.se << endl;
        }
    }


    return 0;
}