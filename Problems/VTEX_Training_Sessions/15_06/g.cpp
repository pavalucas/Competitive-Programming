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

vpi rect(4);

double calcDist(int x1, int y1, int x2, int y2) {
    return  sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double distToRect(int x, int y, int x1, int y1, int x2, int y2) {
    if(x >= x1 && x <= x2) return double(min(abs(y - y1), abs(y - y2)));
    if(y >= y1 && y <= y2) return double(min(abs(x - x1), abs(x - x2)));
    double result = numeric_limits<double>::max();
    rp(i,4) {
        result = min(result, calcDist(x, y, rect[i].fi, rect[i].se));
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    rect[0] = {x1, y1};
    rect[1] = {x1, y2};
    rect[2] = {x2, y2};
    rect[3] = {x2, y1};
    cout << fixed << setprecision(3);
    cout << distToRect(x, y, x1, y1, x2, y2) << endl;
    return 0;
}