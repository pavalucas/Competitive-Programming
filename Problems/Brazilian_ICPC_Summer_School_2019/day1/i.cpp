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


const int MAXN = 52;

int n, z;
long double fat[MAXN];
long double pot[MAXN];

void calcFatPot() {
    pot[0] = 1;
    fat[0] = 1;
    rep(i,1,MAXN) {
        pot[i] = 2 * pot[i-1];
        fat[i] = i * fat[i-1];
    }
}

long double calcExpression(int i) {
    return (fat[n] * pot[n-i]) / (fat[n-i] * fat[i]);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    calcFatPot();
    while(cin >> n >> z) {
        if(z > n) {
            cout << 100.0 << '\n';
            continue;
        }

        long double numerator = 0.0;
        rp(i,z) {
            numerator += calcExpression(i);
            WATCH(numerator);
        }
        long double denom = numerator + calcExpression(z);
        cout << fixed << setprecision(10) << (numerator / denom) * 100.0 << '\n';
    }


    return 0;
}