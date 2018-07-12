#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rp(i, n) for (int i = 0; i < (int)(n); ++i)
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

int n, c;
bool checkDist(int dist, vi& stal) {
	int atDist = stal[0];
	int atC = c-1;
	for(int i = 1; i < n; i++) {
		if(stal[i] - atDist >= dist) {
			atDist = stal[i];
			atC--;
		}
		if(atC <= 0) return true;
	}
	return false;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int test;
    cin >> test;
    rp(t,test) {
    	cin >> n >> c;
    	vi stal(n);
    	rp(i,n) cin >> stal[i];
    	sort(all(stal));
    	int lo = 0;
    	int high = 1e9+1;
    	while(high - lo > 1) {
    		int mid = lo + (high - lo) / 2;
    		if(checkDist(mid, stal)) lo = mid;
    		else high = mid;
    	}
    	cout << lo << endl;
    }
    return 0;
}