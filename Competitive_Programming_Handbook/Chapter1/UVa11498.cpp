#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  while(n != 0) {
    int oa, ob;
    cin >> oa >> ob;
    for(int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      a -= oa;
      b -= ob;
      if(a == 0 || b == 0) cout << "divisa" << endl;
      else if(a > 0 && b > 0) cout << "NE" << endl;
      else if(a < 0 && b > 0) cout << "NO" << endl;
      else if(a < 0 && b < 0) cout << "SO" << endl;
      else cout << "SE" << endl;
    }
    cin >> n;
  }
}