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

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n, h;
    cin >> n >> h;
    vector<pair<ll, ll> > seg(n);
    vll dist(n + 1);
    rp(i,n) {
        ll a, b;
        cin >> a >> b;
        seg[i] = {a, b};
    }
    dist[0] = 0;
    for(int i = 1; i < n; i++) {
        dist[i] = dist[i-1] + seg[i].fi - seg[i-1].se;
    }
    dist[n] = 1e14;
    vll respVec(n);
    ll resp = -1;
    rp(i,n) {
        int pos = upper_bound(all(dist), dist[i] + h - 1) - dist.begin() - 1;
        ll add = h - (dist[pos] - dist[i]);
        respVec[i] = seg[pos].se - seg[i].fi + add;
        WATCH(dist[pos]);
        WATCH(add);
        WATCH(respVec[i]);
        resp = max(resp, respVec[i]);
    }
    cout << resp << endl;
    return 0;
}