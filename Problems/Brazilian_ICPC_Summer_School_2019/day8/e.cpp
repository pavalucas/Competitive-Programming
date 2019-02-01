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

const int MAXN = 100010;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ifstream in("electricity.in");
    ofstream out("electricity.out");
    int n, m;
    int resp = 0;
    in >> n >> m;
    vi a(n), b(m);
    rp(i,n) in >> a[i];
    rp(i,m) in >> b[i];

    sort(all(a));
    reverse(all(a));

    sort(all(b));
    reverse(all(b));

    int curB = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < a[i]; j++) {
            resp += b[curB];
            curB++;
            if(curB >= m) {
                out << resp << '\n';
                return 0;
            }
        }
        resp--;
    }

    out << resp + 1 << '\n';
    return 0;
}