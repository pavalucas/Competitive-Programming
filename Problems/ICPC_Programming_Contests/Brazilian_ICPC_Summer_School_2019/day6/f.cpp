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

#define LC 2*node+1
#define RC 2*node+2
#define REC int node = 0, int L = 0, int R = -1
template <typename T>
struct segtree {
    T op(const T& a, const T& b) {
        // This is THE function you want to change.
        return a+b;
    }
    int N;
    vector<T> tree;
    segtree(int _N) : N(_N) {
        int e = 32 - __builtin_clz(N-1);
        if (N == 1) e = 0;
        N = 1<<e;
        tree.resize(1<<(e+1));
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
    // Does "V[i] = nv"
    T update(int i, const T& nv, REC) {
        if (R == -1) R = N;
        if (i < L || i >= R) return tree[node];
        if (R - L == 1) return tree[node] = nv;
        int m = (L + R)/2;
        return tree[node] = op( update(i, nv, LC, L, m),
                    update(i, nv, RC, m, R));
    }
    // queries the CLOSED interval [i,j]
    T query(int i, int j) {
        return _query(i, j+1);
    }
    T _query(int i, int j, REC) {
        if (R == -1) R = N;
        if (i <= L && R <= j) return tree[node];
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
    int n, k, a, b, q;
    cin >> n >> k >> a >> b >> q;
    vi vec(n, 0);
    segtree<int> segTreeA(n);
    segtree<int> segTreeB(n);
    segTreeA.setup(vec);
    segTreeB.setup(vec);
    rp(i, q) {
        int in1, in2, in3;
        cin >> in1;
        if(in1 == 1) {
            cin >> in2 >> in3;
            in2--;
            vec[in2] += in3;
            segTreeA.update(in2, min(vec[in2], a));
            segTreeB.update(in2, min(vec[in2], b));
        } else {
            cin >> in2;
            in2--;
            int resp = 0;
            WATCH(in2-1);
            if(in2 > 0) resp += segTreeB.query(0, in2-1);
            WATCH(resp);
            WATCH(in2+k);
            if(in2+k-1 < n-1) resp += segTreeA.query(in2+k, n-1);
            WATCH(resp);
            cout << resp << '\n';
        }
    }
    return 0;
}