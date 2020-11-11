#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> tree(n);
  for(int i = 0; i < n; i++) cin >> tree[i];
  sort(tree.rbegin(), tree.rend());
  int resp = -1;
  for(int i = 0; i < n; i++) {
    resp = max(resp, tree[i] + i + 1);
  }
  cout << resp + 1 << endl;
}