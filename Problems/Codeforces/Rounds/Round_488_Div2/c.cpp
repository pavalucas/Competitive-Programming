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
#define PRINT(x...)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl )

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
};

struct Square {
    int xMin, xMax, yMin, yMax;
    Square() : xMin(1000), yMin(1000), xMax(-1000), yMax(-1000) {}
    bool checkPoint(Point& q) {
        return (q.x >= xMin && q.x <= xMax && q.y >= yMin && q.y <= yMax);
    }
};

Square getSquare(Point p[4]) {
    Square s;
    rp(i,4) {
        int a = p[i].x, b = p[i].y;
        s.xMin = min(s.xMin, a);
        s.xMax = max(s.xMax, a);
        s.yMin = min(s.yMin, b);
        s.yMax = max(s.yMax, b);
    }
    return s;
}

void readInput(Point p[4]) {
    rp(i,4) {
        int a, b;
        cin >> a >> b;
        p[i].x = a;
        p[i].y = b;
    }
}

Point getCenter(Point p[]) {
    if(p[0].x == p[2].x) {
        return Point(p[0].x, ((double)p[0].y + p[2].y) / 2);
    }
    WATCH(p[0].y);
    return Point(((double)p[0].x + p[2].x) / 2, p[0].y);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    Point p[4], p1[4];
    readInput(p);
    readInput(p1);
    rp(k,2) {
        Square s = getSquare(p);
        WATCH(s.xMin);
        WATCH(s.xMax);
        WATCH(s.yMin);
        WATCH(s.yMax);

        WATCH(p[0].x);
        WATCH(p[0].y);
        WATCH(p[1].x);
        WATCH(p[1].y);
        WATCH(p[2].x);
        WATCH(p[2].y);
        WATCH(p[3].x);
        WATCH(p[3].y);

        WATCH(p1[0].x);
        WATCH(p1[0].y);
        WATCH(p1[1].x);
        WATCH(p1[1].y);
        WATCH(p1[2].x);
        WATCH(p1[2].y);
        WATCH(p1[3].x);
        WATCH(p1[3].y);

        Point p1Center = getCenter(p1);
        if(s.checkPoint(p1Center)) {
            cout << "YES" << '\n';
            return 0;
        }
        WATCH(p1Center.x);
        WATCH(p1Center.y);
        rp(i,4) {
            WATCH(i);
            if(s.checkPoint(p1[i])) {
                cout << "YES" << '\n';
                return 0;
            }
        }

        rp(i,4) {
            int a = p[i].x, b = p[i].y, a1 = p1[i].x, b1 = p1[i].y;
            p[i].x = a + b;
            p[i].y = a - b;
            p1[i].x = a1 + b1;
            p1[i].y = a1 - b1;
        }

        Point tmp[4];
        memcpy(tmp, p, sizeof(tmp));
        memcpy(p, p1, sizeof(p));
        memcpy(p1, tmp, sizeof(p1));
    }

    cout << "NO" << '\n';

    return 0;
}