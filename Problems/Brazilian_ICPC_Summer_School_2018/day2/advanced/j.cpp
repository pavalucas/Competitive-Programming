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

#define MAXN 100010

// Retorna -1 se a < b, 0 se a = b e 1 se a > b.
int cmp_double(double a, double b = 0, double eps = 1e-9) {
    return a + eps > b ? b + eps > a ? 0 : 1 : -1;
}

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    Point operator+ (const Point &o) const { return Point(x + o.x, y + o.y); }
    Point operator- (const Point &o) const { return Point(x - o.x, y - o.y); }
    Point operator* (const double &o) const { return Point(x * o, y * o); }
    Point operator/ (const double &o) const { return Point(x / o, y / o); }
    double operator* (const Point &o) const { return x * o.x + y * o.y; }
    double operator% (const Point &o) const { return x * o.y - o.x * y; }
    bool operator== (const Point &o) const {
        return cmp_double(x, o.x) == 0 && cmp_double(y, o.y) == 0;
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

double abs(Point p) {
    return sqrt(p * p);
}

struct Circle {
    Point p;
    double r;
    Circle() {}
    Circle(Point p, double r) : p(p), r(r) {}
};

bool in_circle(const Circle &c, const Point &p) {
    return cmp_double(abs(c.p - p), c.r) <= 0;
}

Point circumcenter(Point p, Point q, Point r) {
    Point a = p - r, b = q - r, c = Point(a*(p+r)/2, b*(q+r)/2);
    return Point(c % Point(a.y, b.y), Point(a.x, b.x) % c)/(a % b);
}

int n;
Point p[MAXN];

Circle spanning_circle() {
    random_shuffle(p, p+n);
    Circle c(Point(), -1);
    for (int i = 0; i < n; i++) if (!in_circle(c, p[i])) {
        c = Circle(p[i], 0);
        for (int j = 0; j < i; j++) if (!in_circle(c, p[j])) {
            c = Circle((p[i] + p[j])/2, abs(p[i] - p[j])/2);
            for (int k = 0; k < j; k++) if (!in_circle(c, p[k])) {
                Point o = circumcenter(p[i], p[j], p[k]);
                c = Circle(o, abs(o - p[k]));
            }
        }
    }
    return c;
}

int main() {
    scanf("%d", &n);
    rp(i,n) p[i].read();
    Circle c = spanning_circle();
    printf("%.7f %.7f\n%.7f\n", c.p.x, c.p.y, c.r);

    return 0;
}