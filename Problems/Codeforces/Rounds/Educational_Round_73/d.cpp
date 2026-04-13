#include <bits/stdc++.h>

using namespace std;


#define TRACE(x...)
#define WATCH(x) TRACE( cout << #x" = " << x << endl)
#define PRINT(x) TRACE(printf(x))
#define WATCHR(a, b) TRACE( for(auto c = a; c != b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end()); } )

#define ll long long

const int MAXN = 300010;
int n;
vector<pair<long long, long long> > vec(MAXN);
vector<vector<long long>> dp(MAXN, vector<long long>(3, 0));

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			vec[i] = {a, b};
		}
		for(int i = 0; i < 3; i++) {
			dp[0][i] = vec[0].second * i;
		}
		for(int i = 1; i < n; i++) {
			for(int j = 0; j < 3; j++) {
				ll minValue = numeric_limits<ll>::max();
				for(int k = 0; k < 3; k++) {
					if(vec[i-1].first + k != vec[i].first + j) {
						minValue = min(minValue, dp[i-1][k]);
					}
				}
				dp[i][j] = minValue + vec[i].second * j;
				WATCH(dp[i][j]);
			}
		}
		
		ll resp = numeric_limits<ll>::max();
		for(int i = 0; i < 3; i++) {
			resp = min(resp, dp[n-1][i]);
		}
		cout << resp << '\n';
	} 
	return 0;
}
