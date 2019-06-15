#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int test;
  std::cin >> test;
  for (int t = 0; t < test; t++) {
    int n;
    int64_t ans = 0;
    std::cin >> n;
    std::vector<int64_t> monsters(n);
    std::vector<int64_t> dp(n);
    if (n == 0) {
      std::cout << "Case " << t + 1 << ": " << ans << '\n';
      continue;
    }
    for (int i = 0; i < n; i++) {
      std::cin >> monsters[i];
    }
    dp[0] = monsters[0];
    ans = dp[0];

    for (int i = 1; i < n; i++) {
      dp[i] = std::max(monsters[i], dp[i-1]);
      if (i - 2 >= 0) {
        dp[i] = std::max(dp[i], dp[i-2] + monsters[i]);
      }
      ans = std::max(dp[i], ans);
    }
    std::cout << "Case " << t + 1 << ": " << ans << '\n';
  }
  return 0;
}