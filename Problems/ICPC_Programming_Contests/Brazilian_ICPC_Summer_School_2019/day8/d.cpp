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

// Retorna -1 se a < b, 0 se a = b e 1 se a > b.
int cmp_double(double a, double b = 0, double eps = 1e-11) {
    return a + eps > b ? b + eps > a ? 0 : 1 : -1;
}


const double inf = 1.0/0.0;
const double pi = 2 * acos(0.0);


int main() {
    int x, y, d;
    ifstream in("deepest.in");
    ofstream out("deepest.out");
    in >> x >> y >> d;
    if (x*x + y*y == d*d) {
        out << "Single staircase" << endl;
        return 0;
    }

    long double theta;
    theta = atan2(x, y);
    WATCH(theta);

    long double b;
    if (cmp_double(sin(theta), 0.0) != 0.0)
        b = (long double) x / (2.0*sin(theta)) - d/2.0;
    else
        b = (long double) y / (2.0*cos(theta)) - d/2.0;
    WATCH(b);

    long double a = d + b;
    WATCH(a);

    long double x2 = x - b*sin(theta);
    long double y2 = y - b*cos(theta);
    long double h = d - a;

    out << fixed << setprecision(11);
    if(cmp_double(h, 0.0) <= 0) out << "Impossible" << endl;
    else out << x2 << " " << y2 << " " << h << endl;

    return 0;
}