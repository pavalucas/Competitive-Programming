#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ub upper_bound
#define lb lower_bound
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

#define TRACE(x...)
#define PRINT(x...)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl )
#define MAXN 101

int adjMat[MAXN][MAXN], N;

void floyd() {
	for(int k = 0; k < N; k++)
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
}

int main(void) {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n, m;
	cin >> n >> m;
	N = n;
	rp(i,n) rp(j,n) adjMat[i][j] = INF;
	rp(i,m) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		adjMat[a][b] = c;
	}
	floyd();
	ll resp = 0;
	int num = 0;
	rp(i, n) {
		rp(j,n) {
			TRACE(cout << "[" << i+1 << ", " << j+1 << "] -> " << adjMat[i][j] << endl;)
			if(adjMat[i][j] < INF && i != j) {
				resp += adjMat[i][j];
				num++;
			}
		}
	}
	cout << fixed << setprecision(6);
	cout << (double) resp / num << endl;
	return 0;
}
