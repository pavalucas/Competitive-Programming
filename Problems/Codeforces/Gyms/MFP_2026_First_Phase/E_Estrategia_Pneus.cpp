#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXN = 1e3+10;
const int MAXS = 5;
const int INF = 2e9 + 7;

int t[3], d[3];
int dp[MAXN][MAXS+1];

int main() {
    int n, p, s;
    cin >> n >> p >> s;
    for(int i = 0; i < 3; i++) {
        cin >> t[i];
    }
    for(int i = 0; i < 3; i++) {
        cin >> d[i];
    }
    for(int i = 0; i <= n; i++) {
        dp[i][0] = INF;
    }
    for(int i = 0; i <= s; i++) {
        dp[0][i] = 0;
    }
    for(int i = 0; i <= n; i++) {
        for(int k = 0; k < 3; k++) {
            if(i - d[k] <= 0) {
                int laps_count = min(i, d[k]);
                dp[i][0] = min(dp[i][0], t[k] * laps_count);
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= s; j++) {
            dp[i][j] = dp[i][j-1];
            for(int k = 0; k < 3; k++) {
                int laps_count = min(i, d[k]);
                dp[i][j] = min(dp[i][j], dp[i - laps_count][j-1] + t[k]*laps_count + p);
            }
        }
    }

    cout << dp[n][s] << endl;


    return 0;
}
