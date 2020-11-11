#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios_base::sync_with_stdio(0);cin.tie(0);
  int test;
  cin >> test;
  while(test--) {
    int n;
    cin >> n;
    vector<int> gran(n);
    for(int i = 0; i < n; i++) cin >> gran[i];
    sort(gran.begin(), gran.end());
    int nGran = 1;
    int toEnter = 0;
    for(int i = 0; i < n; i++) {
      if(nGran + toEnter >= gran[i]) {
        nGran += toEnter + 1;
        toEnter = 0;
      } else {
        toEnter++;
      }
    }

    cout << nGran << '\n';
  }
  return 0;
}