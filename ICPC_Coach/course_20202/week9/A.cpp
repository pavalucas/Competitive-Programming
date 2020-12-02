#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  int n, m;
  while(cin >> n >> m) {
    vector<int> coins(m);
    for(int i = 0; i < m; i++) cin >> coins[i];
    vector<int> dp(1000010, 0);
    for(int i = 1; i <= n; i++) {
      for(auto& p : coins) {
        if(i - p >= 0) {
          dp[i] |= (1 - dp[i - p]);
        }
      }
    }
    if(dp[n]) cout << "Stan wins\n";
    else cout << "Ollie wins\n";

  }

}