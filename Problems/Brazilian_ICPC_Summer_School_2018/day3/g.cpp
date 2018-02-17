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


#define TRACE(x...)
#define PRINT(x...)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl )

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

// Retorna -1 se a < b, 0 se a = b e 1 se a > b.
int cmp_double(long double a, long double b = 0, long double eps = 1e-9) {
    return a + eps > b ? b + eps > a ? 0 : 1 : -1;
}

struct Point {
    long double x, y;
    Point() {}
    Point(long double x, long double y) : x(x), y(y) {}
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
};
typedef Point Vector;

const int MAXN = 1000000;
Point p[MAXN];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    rp(i,n) {
        long double a, b;
        cin >> a >> b;
        p[i] = {a, b};
    }
    TRACE(
        rp(i,n) {
            cout << p[i].x << " " << p[i].y << endl;
        }
    )
    if(n <= 3) {
        cout << 0 << endl;
        return 0;
    }

    set<Point> newPoint;
    rp(k, 2) {
        rp(i, n) {
            for(int j = i+1; j < n; j++) {
                Point p1 = (p[i] + p[j]) / 2.0;
                if(newPoint.find(p1) != newPoint.end()) {
                    TRACE(cout << p[i].x << " " << p[i].y << " - " << p[j].x << " " << p[j].y << endl;)
                    cout << k + 1 << endl;
                    return 0;
                } else {
                    newPoint.insert(p1);
                }
            }
        }
        n = newPoint.size();
        int count = 0;
        for(auto& newP : newPoint) {
            p[count] = newP;
            count++;
        }
        newPoint.clear();
    }
    return 0;
}
