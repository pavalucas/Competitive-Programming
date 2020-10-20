#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  while(cin >> n >> m) {
      vector<int> vec(n);
      for(int i = 0; i < n; i++) cin >> vec[i];
      map<int, vector<int>> mapVec;
      for(int i = 0; i < n; i++) {
        if(mapVec.count(vec[i])) {
          mapVec[vec[i]].emplace_back(i);
        } else {
          vector<int> tmp{i};
          mapVec[vec[i]] = tmp;
        }
      }
      for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if(mapVec.count(b) && mapVec[b].size() >= a) {
          cout << mapVec[b][a-1] + 1 << '\n';
        } else {
          cout << 0 << '\n';
        }
      }
  }
}
