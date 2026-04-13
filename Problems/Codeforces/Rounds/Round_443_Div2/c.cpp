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
	int n;
	cin >> n;
	vector<char> order;
	vi vAnd, vOr, vXor;
	rp(i, n) {
		char a;
		int b;
		cin >> a >> b;
		if(find(all(order), a) == order.end()) order.pb(a);
		if(a == '&') vAnd.pb(b);
		if(a == '|') vOr.pb(b);
		if(a == '^') vXor.pb(b);
	}
	int respAnd = -1;
	if(vAnd.size() > 0) {
		respAnd = vAnd[0];
		for(int i = 1; i < vAnd.size(); i++) respAnd &= vAnd[i];
	}
	
	int respOr = -1;
	if(vOr.size() > 0) {
		respOr = vOr[0];
		for(int i = 1; i < vOr.size(); i++) respOr |= vOr[i];
	}
	
	int respXor = -1;
	if(vXor.size() > 0) {
		respXor = vXor[0];
		for(int i = 1; i < vXor.size(); i++) respXor ^= vXor[i];
	}

	cout << order.size() << endl;
	rp(i, order.size()) {
		if(order[i] == '&' and respAnd != -1)
			cout << "& " << respAnd << endl;
		if(order[i] == '|' and respOr != -1)
			cout << "| " << respOr << endl;
		if(order[i] == '^' and respXor != -1)
			cout << "^ " << respXor << endl;
	}
	return 0;
}
