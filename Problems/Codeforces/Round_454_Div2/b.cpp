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

char mat[9][9];

int main(void) {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int row = 0, col = 0;
	rp(i,11) {
		string line;
		getline(cin, line);
		col = 0;
		rp(j,line.size()) {
			TRACE(cout << line[j];)
			if(line[j] == '.') {
				mat[row][col] = '.';
				col++;
			}
			else if(line[j] == 'x') {
				mat[row][col] = 'x';
				col++;
			}
			else if(line[j] == 'o') {
				mat[row][col] = 'o';
				col++;
			}
		}
		TRACE(cout << endl;)
		if(i != 3 && i != 7) row++;
	}
	TRACE(
		rp(i,9) {
			rp(j,9) cout << mat[i][j];
			cout << endl;
		}
	)
	int a, b;
	cin >> a >> b;
	a--; b--;
	a %= 3; b %= 3;
	bool move = false;
	for(int i = 3*a; i < 3*a + 3; i++) {
		for(int j = 3*b; j < 3*b + 3; j++) {
			if(mat[i][j] == '.') {
				mat[i][j] = '!';
				move = true;
			}
		}
	}

	if(!move) {
		rp(i,9)
			rp(j,9)
				if(mat[i][j] == '.') mat[i][j] = '!';
	}

	rp(i,9) {
		if(i % 3 == 0 and i != 0) cout << endl;
		rp(j,9) {
			if(j % 3 == 0 and j != 0) cout << " ";
			cout << mat[i][j];
		}
		cout << endl;
	}

	return 0;
}
