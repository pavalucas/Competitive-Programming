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

struct Point {
    double x, y;
    Point() {}
    Point(double a, double b) : x(a), y(b) {}
    Point operator- (const Point &o) { return Point(x - o.x, y - o.y); }
    Point operator+ (const Point &o) { return Point(x + o.x, y + o.y); }
    double operator* (const Point &o) { return o.x*x + o.y*y; }
    double operator% (const Point &o) { return x*o.y - o.x*y; }

    void read() {
        scanf("%lf %lf", &x, &y);
    }
};

double abs(Point a) {
    return sqrt(a*a);
}

//angle pqr
double findSen(Point p, Point q) {
	return ((p % q) / (abs(p) * abs(q)));
}

int main(void)
{
    Point p1 = Point();
    Point p2 = Point();
    Point p3 = Point();
    Point p4 = Point();
    p1.read();
    p2.read();
    p3.read();
    p4.read();

    Point vec1 = p2 - p1;
    Point vec2 = p4 - p3;
	double len1 = abs(vec1);
	double len2 = abs(vec2);
    printf("%.7lf %.7lf\n", len1, len2);
	
	Point sum = vec1 + vec2;
	printf("%.7lf %.7lf\n", sum.x, sum.y);
	printf("%.7lf %.7lf\n", vec1*vec2, vec1%vec2);
	printf("%.7lf\n", abs(len1 * len2 * findSen(vec1, vec2)) / 2);


    return 0;
}
