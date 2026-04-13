#include <bits/stdc++.h>
using namespace std;

#define INF 0x3F3F3F3F
#define INFLL 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

#define contOnes __builtin_popcountl
#define logLow(X) (X <= 0 ? 0 : 31 - __builtin_clz(X))
#define logUpper(X) (X <= 1 ? 0 : 32 - __builtin_clz(X-1))
#define pow2(X) ((X)*(X))

#define watch(x) cout << (#x) << " is " << (x) << endl
#define mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define unico(x) x.erase(unique(all(x)), (x).end())

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<vd> vvd;

const double inf = 1.0/0.0;
const double pi = 2 * acos(0.0);

// Retorna -1 se a < b, 0 se a = b e 1 se a > b.
int cmp_double(double a, double b = 0, double eps = 1e-9) {
    return a + eps > b ? b + eps > a ? 0 : 1 : -1;
}

#define LC 2*node+1
#define RC 2*node+2
#define REC int node = 0, int L = 0, int R = -1
template <typename T, typename T2>
struct segtree_lazy {
    T op(const T& a, const T& b) {
        // This is THE function you want to change.
        return a + b;
    }
    void recompute(int node, int L, int R, const T2& upd) {
        // Change this also. This is an example for the pirate.
        if (!islazy[node]) lazy[node] = 0;
        islazy[node] = true;
        if (upd != 0) {     // 2 means set to 0, 3 means set to 1
            lazy[node] = upd;
            tree[node] = (upd) * (R-L);
        }
    }
    int N;
    vector<T> tree;
    vector<T2> lazy;
    vector<bool> islazy;
    segtree_lazy(int _N) : N(_N) {
        int e = 32 - __builtin_clz(N-1);
        if (N == 1) e = 0;
        N = 1<<e;
        tree.resize(1<<(e+1));
        lazy.resize(1<<(e+1));
        islazy.resize(1<<(e+1), false);
    }
    // Vector to be in the leaves
    void setup(vector<T>& V, REC) {
        if (R == -1) R = N;
        if (L >= sz(V)) return;
        if (R - L == 1) {
            tree[node] = V[L];
            return;
        }
        int m = (L + R)/2;
        setup(V, LC, L, m);
        setup(V, RC, m, R);
        tree[node] = op(tree[LC], tree[RC]);
    }
    void push(int node, int L, int R) {
        if (!islazy[node]) return;
        islazy[node] = false;
        int m = (L+R)/2;
        recompute(LC, L, m, lazy[node]);
        recompute(RC, m, R, lazy[node]);
    }
    void update(int i, int j, const T2& upd) {
        _update(i, j+1, upd);
    }
    T _update(int i, int j, const T2& upd, REC) {
        if (R == -1) R = N;
        if (j <= L || i >= R) return tree[node];
        if (i <= L && R <= j) {
            recompute(node, L, R, upd);
            return tree[node];
        }
        push(node, L, R);
        int m = (L + R)/2;
        return tree[node] = op( _update(i, j, upd, LC, L, m),
                    _update(i, j, upd, RC, m, R));
    }
    // queries the CLOSED interval [i,j]
    T query(int i, int j) {
        return _query(i, j+1);
    }
    T _query(int i, int j, REC) {
        if (R == -1) R = N;
        if (i <= L && R <= j) return tree[node];
        push(node, L, R);
        int m = (L + R)/2;
        if (i >= m) return _query(i, j, RC, m, R);
        else if (j <= m) return _query(i, j, LC, L, m);
        return op(_query(i, j, LC, L, m), _query(i, j, RC, m, R));
    }
};
#undef LC
#undef RC
#undef REC

int main() {
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    segtree_lazy<double, double> seg(n);
    vector<double> vec(n);
    for(auto& x : vec) cin >> x;
    seg.setup(vec);
    for(int i = 0; i < q; i++) {
        string s;
        cin >> s;
        if(s[0] == 'g') {
            int a;
            cin >> a;
            --a;
            double resp = seg.query(a, a);
            cout << fixed << setprecision(10);
            cout << resp << '\n';
        } else {
            int a, b;
            cin >> a >> b;
            --a; --b;
            double val = seg.query(a, b);
            val /= b - a + 1;
            seg.update(a, b, val);
        }
    }
    return 0;
}