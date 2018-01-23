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

#define TRACE(x...)
#define PRINT(x...)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl )
#define MAXN 1000010

int np, p[MAXN];
int lp[MAXN];

void sieve(int n) {
    for (int i = 2; i < n; i++)
        lp[i] = i;
    for (int i = 4; i < n; i += 2)
        lp[i] = 2;
    for (int i = 3; i*i < n; i += 2) if (lp[i] == i)
            for (int j = i*i; j < n; j += i) if (lp[j] == j)
                lp[j] = i;
    np = 0;
    p[np++] = 2;
    for (int i = 3; i < n; i += 2)
        if (lp[i] == i)
            p[np++] = i;
}

int main(void) {
	ios_base::sync_with_stdio(0);cin.tie(0);
    int k;
    cin >> k;
    sieve(1000000);
    cout << p[k-1] << endl;
	return 0;
}
