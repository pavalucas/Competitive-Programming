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

set<char> word;
string alph = "abcdefghijklmnopqrstuvwxyz";

int main(void) {
	ios_base::sync_with_stdio(0);cin.tie(0);
	rp(i,alph.size()) word.insert(alph[i]);
	int n, resp = 0;
	bool ok = false;
	cin >> n;
	rp(i,n) {
		char a;
		string b;
		cin >> a;
		cin >> b;
		set<int> aux;
		TRACE(
			for(auto p : word) cout << p;
			cout << endl;
		)
		if(a == '!') {
			rp(j,b.size()) aux.insert(b[j]);
			rp(j,alph.size()) {
				if(aux.find(alph[j]) == aux.end())
					word.erase(alph[j]);
			}
			if(ok) resp++;
		} else if(a == '.') {
			rp(j,b.size()) word.erase(b[j]);
		} else if(a == '?' and i != n-1) {
			word.erase(b[0]);
			if(ok) resp++;
		}
		if(word.size() == 1) ok = true;
	}
	cout << resp << endl;
	return 0;
}
