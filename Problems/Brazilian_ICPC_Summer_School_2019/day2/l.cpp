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

ll convertToInt(string s) {
	ll ret = 0, count = 1;
	for(int i = sz(s)-1; i >= 0; i--) {
		ll at = s[i] - '0';
		ret += at * count;
		count *= 10;
	}
	return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int k;
    cin >> k;
    ll maxSize = 0, minNum = -1;
    rp(i,k) {
    	string s;
    	cin >> s;
    	minNum = max(minNum, convertToInt(s));
    	maxSize = max(maxSize, (ll)sz(s));
    }
    ll maxNum = 0, count = 1;
    rp(i,maxSize) {
    	maxNum += 9 * count;
    	count *= 10;
    }
    cout << max(count/10, minNum) << '\n';
    cout << maxNum << '\n';
    return 0;
}
