/* Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1241 */

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

bool check(string a, string b) {
	int tam = a.size() - b.size();
	for(int i = 0; i < b.size(); i++) {
		if(a[tam + i] != b[i])
			return false;
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	string a, b;
	cin >> n;
	rp(i, n) {
		cin >> a >> b;
		bool ok = (a.size() >= b.size());
		if(ok) {
			ok = check(a,b);
		}

		if(ok) cout << "encaixa" << endl;
		else cout << "nao encaixa" << endl;
	}
	return 0;
}
