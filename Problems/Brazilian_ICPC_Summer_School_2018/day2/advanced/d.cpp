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
typedef vector<long double> vd;
typedef vector<vd> vvd;

const long double inf = 1.0/0.0;
const long double pi = 2 * acos(0.0);

#define MAXN 101015

#define TRACE(x...)
#define PRINT(x...)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl )

// Retorna -1 se a < b, 0 se a = b e 1 se a > b.
double EPS = 1e-9;
int cmp_double(long double x, long double y = 0, long double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


struct Point {
    ll x, y;
    Point() {}
    Point(ll x, ll y) : x(x), y(y) {}

    Point operator+ (const Point &o) const { return Point(x + o.x, y + o.y); }
    Point operator- (const Point &o) const { return Point(x - o.x, y - o.y); }
    Point operator* (const ll &o) const { return Point(x * o, y * o); }
    Point operator/ (const ll &o) const { return Point(x / o, y / o); }
    double operator* (const Point &o) const { return x * o.x + y * o.y; }
    double operator% (const Point &o) const { return x * o.y - o.x * y; }
    int cmp(Point q) const {
        if (int t = ::cmp_double(x, q.x)) return t;
        return ::cmp_double(y, q.y);
    }
    bool operator== (const Point &o) const {
        return ::cmp_double(x, o.x) == 0 && ::cmp_double(y, o.y) == 0;
    }
    bool operator< (const Point &o) const {
        return x != o.x ? x < o.x : y < o.y;
    }

    void read() {
        scanf("%lf %lf", &x, &y);
    }
    void print() {
        printf("(%lf,%lf)\n", x, y);
    }
};

long double ccw(Point p, Point q, Point r) {
    return cmp_double((q - p) % (r - p));
}
inline long double angle(Point p, Point q, Point r) {
    Point u = p - q, v = r - q;
    return atan2(u % v, u * v);
}
bool between(Point p, Point q, Point r) {
    return ccw(p, q, r) == 0 && cmp_double((p - q) * (r - q)) <= 0;
}

int n;
Point p[MAXN];

int in_poly(Point q) {
    int l = 0, r = n;
    while (l+1 < r) {
        int m = (l+r)/2;
        if (ccw(p[m], p[0], q) == 0)
            return between(p[0], q, p[m]);
        if (ccw(p[m], p[0], q) < 0) l = m;
        else r = m;
    }
    return cmp_double(angle(p[0], q, p[l]) + angle(p[l], q, p[r]) + angle(p[r], q, p[0])) != 0;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int m, k;
    ll a, b;
    cin >> n >> m >> k;
    int count = 0;
    rp(i,n) {
        cin >> a >> b;
        p[i] = {a, b};
    }
    rp(i,m) {
        cin >> a >> b;
        Point temp = {a, b};
        count += in_poly(temp);
        if(count >= k) break;
    }
    if(count >= k) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}