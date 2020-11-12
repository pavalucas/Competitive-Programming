#include <bits/stdc++.h>

using namespace std;

#define MAXN 10010

int main() {
  int test;
  cin >> test;
  while(test--) {
    int val, n;
    cin >> val;
    cin >> n;
    vector<vector<int>> dp(n+1, vector<int>(MAXN, INT_MAX));
    vector<int> coins(n+1);

    for(int i = 1; i <= n; i++) {
      cin >> coins[i];
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = 0; j < MAXN; j++) {
        dp[i][j] = min(dp[i][j], dp[i-1][j]);

        if(j - coins[i] >= 0 && dp[i-1][j - coins[i]] < INT_MAX) {
          dp[i][j] = min(dp[i][j], dp[i-1][j - coins[i]] + 1);
        }
      }
    }
    int respVal, respQnt;
    for(int i = val; i < MAXN; i++) {
      if(dp[n][i] < INT_MAX) {
        respQnt = dp[n][i];
        respVal = i;
        break;
      }
    }
    cout << respVal << " " << respQnt << '\n';
  }
}