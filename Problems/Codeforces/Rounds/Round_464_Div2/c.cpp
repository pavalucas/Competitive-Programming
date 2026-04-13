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

#define TRACE(x...)
#define PRINT(x...)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl )

#define MAXN 100010

// Retorna -1 se a < b, 0 se a = b e 1 se a > b.
int cmp_double(double a, double b = 0, double eps = 1e-9) {
    return a + eps > b ? b + eps > a ? 0 : 1 : -1;
}


int main(void) {
	ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    vi vec(n);
    rp(i,n) cin >> vec[i];
    int s, f, k;
    cin >> s >> f;
    k = f-s;
    int bestSum;
    int sum = 0;
    int pos = 0;
    rp(i,k) sum += vec[i];
    bestSum = sum;
    int resp = MAXN + 100;
    for(int i = 1; i < n; i++) {
        sum -= vec[(i - 1) % n];

        sum += vec[(i + k - 1) % n];

        if(sum > bestSum) {
            bestSum = sum;
            pos = i;
        } else if(sum == bestSum) {
            TRACE(cout << "entrei" << endl;
                cout << sum << endl;
                cout << i << endl;)
            int respAt;
            if(s - i <= 0) respAt = n + (s - i);
            else respAt = s - i;
            if(respAt < resp) {
                resp = respAt;
                pos = i;
            }
        }
    }
    if(s - pos <= 0) resp = n + (s - pos);
    else resp = s - pos;
    cout << resp << endl;

	return 0;
}
