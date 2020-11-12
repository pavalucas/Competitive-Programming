#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  vector<int> vec{a, b, c};
  vector<int> dp(n+10, -1);
  dp[0] = 0;
  int resp = 0;
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j < 3; j++) {
      if(i - vec[j] >= 0 && dp[i - vec[j]] >= 0) {
        dp[i] = max(dp[i], dp[i - vec[j]] + 1);
      }
    }
  }
  cout << dp[n] << '\n';
}