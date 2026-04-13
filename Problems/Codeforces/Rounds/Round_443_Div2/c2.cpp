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
	int vet0[10] = {0};
	int vet1[10];
	rp(i,10) vet1[i] = 1;
	TRACE(
		rp(i,10) cout << vet0[i];
		cout << endl;
		rp(i,10) cout << vet1[i];
		cout << endl;
			)
	int n;
	cin >> n;
	rp(i,n) {
		char a;
		int b;
		unsigned int val;
		cin >> a >> b;
		rp(j,10) {
			val = (b & (1<<j))>>j;
			if(a == '|') {
				vet0[j] |= val;
				vet1[j] |= val;
			}
			if(a == '&') {
				vet0[j] &= val;
				vet1[j] &= val;
			}
			if(a == '^') {
				vet0[j] ^= val;
				vet1[j] ^= val;
			}
		}
	}
	TRACE(
		rp(i,10) cout << vet0[i];
		cout << endl;
		rp(i,10) cout << vet1[i];
		cout << endl;
			)
	int respOr = 0, respXor = 0, respAnd = 1023;
	rp(i,10) {
		int pos = 1<<i;
		if(vet0[i] == 0 and vet1[i] == 0) respAnd &= ~pos;
		if(vet0[i] == 1 and vet1[i] == 1) respOr |= pos;
		if(vet0[i] == 1 and vet1[i] == 0) respXor ^= pos;
	}
	cout << "3" << endl;
	cout << "| " << respOr << endl;
	cout << "& " << respAnd << endl;
	cout << "^ " << respXor << endl;
	return 0;
}
