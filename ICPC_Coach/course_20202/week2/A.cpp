#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  while(n + m != 0) {
    unordered_set<int> jack;
    for(int i = 0; i < n; i++) {
      int a;
      cin >> a;
      jack.emplace(a);
    }

    int result = 0;
    for(int i = 0; i < m; i++) {
      int a;
      cin >> a;
      if(jack.count(a)) result++;
    }
    cout << result << '\n';
    cin >> n >> m;
  }


}