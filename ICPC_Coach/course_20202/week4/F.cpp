#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n, m;
  cin >> n >> m;
  set<int> alive;
  vector<int> answer(n, 0);
  for (int i = 0; i < n; i++) alive.insert(i);

  for (int i = 0; i < m; i++) {
      int l, r, x;
      cin >> l >> r >> x;
      l--, r--, x--;
      auto it = alive.lower_bound(l);
      vector<int> toErase;
      while(it != alive.end()){
          int cur = *it;
          if(cur > r) break;
          if(cur != x){
              toErase.emplace_back(cur);
              answer[cur] = x+1;
          }
          it++;
      }

      for (auto& p : toErase) alive.erase(p);
  }

  for(auto& p : answer) {
    cout << p << " ";
  }
  cout << '\n';
}