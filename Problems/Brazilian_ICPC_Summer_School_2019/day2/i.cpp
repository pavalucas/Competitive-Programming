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

int main()
{
	long double r, R, n;
	cin >> r >> R >> n;
	long double constant = (2 * M_PI) / n;
	long double constatInt = (2 * M_PI) / 4;
	long double q1 = n;
	long double q2 = (long double)((ll) (n-1) / 2);
	long double q3 = (n-1) - q2;

	long double q12 = 2*(n-1) + 1;
	long double q22 = (n-1);
	long double q32 = 0.0;

	long double resp = (q1*r) * constatInt + (q2*(R-r) + q3*R) * constant;
	long double resp2 = (q12*r) * constatInt + (q22*(R-r) + q32*R) * constant;

	WATCH(resp);
	WATCH(resp2);
	cout << fixed << setprecision(10);
	cout << min(resp, resp2) << '\n';


	return 0;
}