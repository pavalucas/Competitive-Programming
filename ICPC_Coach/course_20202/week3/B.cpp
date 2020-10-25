#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    string s = "";
    for(int i = 0; i < n; i++) {
      string tmp;
      cin >> tmp;
      s += tmp;
    }
    int resp = 0;
    for(int i = 0; i < s.size() - 1; i++) {
      if(s[i] == s[i+1]) resp++;
    }
    cout << resp + 1 << '\n';
    return 0;
}