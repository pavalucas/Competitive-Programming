#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<long long> vec(n), sumVec(n);
  for(int i = 0; i < n; i++) cin >> vec[i];
  sumVec[0] = vec[0];
  for(int i = 1; i < n; i++) sumVec[i] = vec[i] + sumVec[i-1];
  for(int i = 0; i < m; i++) {
    long long a;
    cin >> a;
    auto it = lower_bound(sumVec.begin(), sumVec.end(), a);
    int pos;
    if(it != sumVec.end()) {
      pos = it - sumVec.begin();
    } else {
      pos = n - 1;
    }
    long long val = 0;
    if(pos > 0) val = sumVec[pos-1];
    cout << pos + 1 << " " << a - val << '\n';

  }
}