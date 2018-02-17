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
#define rp(i, n) for(int i=0; i < int(n); i++)

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

#define TRACE(x...) x
#define PRINT(x...)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl )

#define MAXN 100010

// Retorna -1 se a < b, 0 se a = b e 1 se a > b.
int cmp_double(double a, double b = 0, double eps = 1e-9) {
    return a + eps > b ? b + eps > a ? 0 : 1 : -1;
}

int mat[101][101] = {0};
map<int, vi> mapa;

int main(void) {
	ios_base::sync_with_stdio(0);cin.tie(0);
    int n, a, firstVal, atVal;
    cin >> n;
    rp(i, 2*n) {
        cin >> a;
        if(mapa.find(a) != mapa.end()) {
            firstVal = a;
        } else {
            vi vec;
            mapa.insert(mp(a, vec));
        }
        atVal = a;
        rp(j, n - 1) {
            cin >> a;
            mapa[atVal].pb(a);
        }
    }

    mat[0][0] = firstVal;
    for(int i = 1; i < n; i++) {
        mat[i][0] = mapa[firstVal][i - 1];
        mat[0][i] = mapa[firstVal][i + n - 2];
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            mat[i][j] = mapa[mat[i][0]][j-1];
        }
    }

    rp(i, n) {
        rp(j, n) {
            cout << mat[i][j] << " ";
        }
    }
    cout << endl;

	return 0;
}
