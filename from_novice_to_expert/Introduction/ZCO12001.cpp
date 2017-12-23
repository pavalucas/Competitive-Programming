#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define rp(i, n) for(int i=0; i < int(n); i++)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

#define TRACE(x...)
#define PRINT(x...)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl )

int main(void) {
	ios_base::sync_with_stdio(0);cin.tie(0);
	stack<int> bracket;
	int n;
	int a, maxDepth = 0, maxBetPair = 0, curDepth = 0, curBetPair = 0;
	int posDepth, posBetPair, posMaxBetPair;
	cin >> n;
	rp(i,n) {
		cin >> a;
		if(a == 1) {
			bracket.push(1);
			curDepth++;
			curBetPair++;
			if(curDepth > maxDepth) {
				maxDepth = curDepth;
				posDepth = i + 1;
			}
			if(bracket.size() == 1) {
				posBetPair = i + 1;
			}
		} else {
			bracket.pop();
			curDepth--;
			curBetPair++;
			WATCH(bracket.size());
			if(bracket.size() == 0) {
				if(curBetPair > maxBetPair) {
					maxBetPair = curBetPair;
					posMaxBetPair = posBetPair;
				}
				curBetPair = 0;
			}
		}
		WATCH(curBetPair);
	}
	cout << maxDepth << " " << posDepth << " " << maxBetPair << " " << posMaxBetPair << endl;
	return 0;
}
