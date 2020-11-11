#include <bits/stdc++.h>

using namespace std;

vector<int> client(50, 0);

int main() {
  int n, t;
  vector<pair<int, int>> vec;
  cin >> n >> t;
  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    vec.emplace_back(make_pair(a, b));
  }
  sort(vec.rbegin(), vec.rend());

  for(int i = 0; i < n; i++) {
    int a = vec[i].first;
    int b = vec[i].second;
    for(int j = min(b, t-1); j >= 0; j--) {
      if(a > client[j]) {
        client[j] = a;
        break;
      }
    }
  }

  int resp = 0;
  for(int i = 0; i < t; i++) {
    resp += client[i];
  }
  cout << resp << '\n';
}