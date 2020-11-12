#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, p;
  cin >> n >> p;
  vector<int> vec(n);
  vector<int> dp(n);
  for(int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  dp[0] = vec[0] - p;
  for(int i = 1; i < n; i++) {
    dp[i] = max(dp[i-1] + vec[i] - p, vec[i] - p);
  }
  int resp = 0;
  for(int i = 0; i < n; i++) {
    resp = max(resp, dp[i]);
  }
  cout << resp << '\n';
}