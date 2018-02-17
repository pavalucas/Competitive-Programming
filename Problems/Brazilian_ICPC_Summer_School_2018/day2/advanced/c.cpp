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

#define MAXN 200010

#define TRACE(x...)
#define PRINT(x...)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl )

// Retorna -1 se a < b, 0 se a = b e 1 se a > b.
int cmp_double(long double a, long double b = 0, long double eps = 1e-9) {
    return a + eps > b ? b + eps > a ? 0 : 1 : -1;
}


struct Point {
    long double x, y;
    int i;
    Point() {}
    Point(long double x, long double y, int i = 0) : x(x), y(y), i(i) {}
    Point operator+ (const Point &o) const { return Point(x + o.x, y + o.y); }
    Point operator- (const Point &o) const { return Point(x - o.x, y - o.y); }
    Point operator* (const long double &o) const { return Point(x * o, y * o); }
    Point operator/ (const long double &o) const { return Point(x / o, y / o); }
    long double operator* (const Point &o) const { return x * o.x + y * o.y; }
    long double operator% (const Point &o) const { return x * o.y - o.x * y; }
    bool operator== (const Point &o) const {
        return cmp_double(x, o.x) == 0 && cmp_double(y, o.y) == 0;
    }
    bool operator< (const Point &o) const {
        return x != o.x ? x < o.x : y < o.y;
    }
    void read() {
        scanf("%Lf %Lf", &x, &y);
    }
    void print() {
        printf("(%Lf,%Lf)\n", x, y);
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

long double distPoint(Point a, Point b) {
    return sqrt(((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)));
}

int n, k;
Point p[MAXN], h[MAXN];

void convex_hull() {
    sort(p, p+n);
    k = 0;
    h[k++] = p[0];
    for (int i = 1; i < n; i++) {
        if (i != n-1 && ccw(p[0], p[n-1], p[i]) >= 0) continue;
        while (k > 1 && ccw(h[k-2], h[k-1], p[i]) <= 0) k--;
        h[k++] = p[i];

    }
    for (int i = n-2, lim = k; i >= 0; i--) {
        if (i != 0 && ccw(p[n-1], p[0], p[i]) >= 0) continue;
        while (k > lim && ccw(h[k-2], h[k-1], p[i]) <= 0) k--;
        h[k++] = p[i];
    }
    k--;
}

// area de p
long double poly_area() {
    long double s = 0;
    for (int i = 0; i < k; i++)
        s += h[i] % h[(i+1) % k];
    return abs(s/2);
}

int main(void) {
    cin >> n;
    rp(i,n) {
        long double a, b;
        scanf("%Lf %Lf", &a, &b);
        p[i] = Point(a, b, i);
    }
    convex_hull();
    printf("%d\n", k);
    rp(i, k) printf("%d ", h[i].i + 1);
    printf("\n");
    long double peri = .0;
    for(int i = 0; i < k; i++) peri += distPoint(h[i], h[(i+1)%k]);
    printf("%.10Lf\n", peri);
    long double area = poly_area();
    printf("%Lf\n", area);

    return 0;
}