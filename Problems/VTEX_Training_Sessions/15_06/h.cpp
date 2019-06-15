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

const int MAXN = 1000010;

int np;
set<int> pSet;
int p[MAXN];
int lp[MAXN];
int maxDiff[MAXN];

void sieve(int n) {
    for (int i = 2; i < n; i++)
        lp[i] = i;
    for (int i = 4; i < n; i += 2)
        lp[i] = 2;
    for (int i = 3; i*i < n; i += 2) if (lp[i] == i)
            for (int j = i*i; j < n; j += i) if (lp[j] == j)
                lp[j] = i;
    np = 0;
    for (int i = 3; i < n; i += 2)
        if (lp[i] == i) {
            p[np++] = i;
            pSet.insert(i);
        }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    sieve(MAXN);
    int n;
    cin >> n;
    maxDiff[4] = 0;
    for(int i = 0; i < np; i++) {
        for(int j = 0; j <= min(1000, i); j++) {
            //WATCH(p[i]);
            //WATCH(p[j]);
            if(p[i] + p[j] < MAXN) {
                maxDiff[p[i] + p[j]] = max(maxDiff[p[i] + p[j]], p[i] - p[j]);
            } else break;
        }
    }

    int step = 0;
    int ini = n;
    while(ini >= 4) {
        WATCH(ini);
        WATCH(maxDiff[ini]);
        ini = maxDiff[ini];
        step++;
    }

    cout << step << endl;

    return 0;
}