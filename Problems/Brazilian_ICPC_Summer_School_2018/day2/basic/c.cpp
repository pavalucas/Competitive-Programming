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
        printf("%.7lf %.7lf\n", x, y);
    }
};
typedef Point Vector;
double abs(Point p) {
    return sqrt(p * p);
}
Vector norm(Vector v) {
    return v / abs(v);
}
double ccw(Point p, Point q, Point r) {
    return cmp_double((q - p) % (r - p));
}
// angulo pqr
inline double angle(Point p, Point q, Point r) {
    Point u = p - q, v = r - q;
    return atan2(u % v, u * v);
}
// retorna true se q esta no segmento [p,r]
bool between(Point p, Point q, Point r) {
    return ccw(p, q, r) == 0 && cmp_double((p - q) * (r - q)) <= 0;
}
struct Segment {
    Point p, q;
    Segment() {}
    Segment(Point p, Point q) : p(p), q(q) {}
};
bool in_segment(Point p, Segment s) {
    double t;
    Vector v = s.q - s.p;
    if (cmp_double(v.x, 0) != 0)
        t = (p.x - s.p.x) / v.x;
    else
        t = (p.y - s.p.y) / v.y;
    return cmp_double(t, 0) >= 0 && cmp_double(t, 1) <= 0 && s.p + v * t == p;
}
struct Line {
    Vector v;
    Point p;
    // implementar init() se quiser eq da reta na forma ax + by = c
    int a, b, c;
    void init() {
        a = -v.y;
        b = v.x;
        c = a * p.x + b * p.y;
        int d = abs(__gcd(a, __gcd(b, c)));
        if (d != 1)
            a /= d, b /= d, c /= d;
        if (a < 0)
            a = -a, b = -b, c = -c;
        else if (a == 0 && b < 0)
            b = -b, c = -c;
    }
    Line() {}
    Line(Point p, Point q) : v(q-p), p(p) {
        init();
    }
    Line(Segment s) : v(s.q-s.p), p(s.p) {
        //init();
    }
    Point operator() (double t) const { return p + v * t; }
    Vector normal() {
        return Vector(-v.y, v.x);
    }
};
pair<double, double> line_intersection(Line a, Line b) {
    double den = a.v % b.v;
    if (den == 0)
        return make_pair(inf, inf);
    double t = -(b.v % (b.p - a.p)) / den;
    double s = -(a.v % (b.p - a.p)) / den;
    return make_pair(t, s);
}
vector<Point> segment_intersection(Segment a, Segment b) {
    vector<Point> resp;
    Line la = Line(a), lb = Line(b);
    pair<double, double> pdd = line_intersection(la, lb);
    double t = pdd.first, s = pdd.second;
    WATCH(t);
    WATCH(s);
    if (t == inf) {
        TRACE(cout << "entrei" << endl;)
        if (in_segment(b.p, a))
            resp.pb(b.p);
        if (in_segment(b.q, a))
            resp.pb(b.q);
        if (in_segment(a.p, b))
            resp.pb(a.p);
        if (in_segment(a.q, b))
            resp.pb(a.q);
        if(resp.size() == 0)
            resp.pb(Point(inf, inf));
        return resp;
    }
    if (cmp_double(t, 0) < 0 || cmp_double(t, 1) > 0)
    {
        TRACE(printf("Entrei\n");)
        resp.pb(Point(inf, inf));
        return resp;
    }
    if (cmp_double(s, 0) < 0 || cmp_double(s, 1) > 0)
    {
        TRACE(printf("Entrei\n");)
        resp.pb(Point(inf, inf));
        return resp;
    }
    resp.pb(la(t));
    return resp;
}

int main(void)
{
    Point p1 = Point(), p2 = Point(), p3 = Point(), p4 = Point();
    p1.read();
    p2.read();
    p3.read();
    p4.read();
    Segment a = Segment(p1, p2);
    Segment b = Segment(p3, p4);
    if(p1 == p2 && p3 == p4) {
        if(p1 == p3) p1.print();
        else printf("Empty\n");
    } else if(p1 == p2) {
        if(in_segment(p1, b)) p1.print();
        else printf("Empty\n");
    } else if(p3 == p4) {
        if(in_segment(p3, a)) p3.print();
        else printf("Empty\n");
    } else {
        vector<Point> inter = segment_intersection(a, b);
        if(inter.size() == 1) {
            if(inter[0].x == inf) printf("Empty\n");
            else inter[0].print();
        } else {
            sort(all(inter));
            int len = (int)inter.size();
            rp(i,len-1) {
                if(!(inter[i] == inter[i+1]))
                    inter[i].print();
            }
            inter[len-1].print();
        }
    }
    return 0;
}