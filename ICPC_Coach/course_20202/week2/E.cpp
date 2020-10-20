#include <bits/stdc++.h>

using namespace std;

bool sortStr(string& a, string& b) {
  return a.size() < b.size();
}

int main() {
  int test;
  cin >> test;
  while(test--) {
    int n;
    cin >> n;
    vector<string> vecStr(n);
    for(int i = 0; i < n; i++) cin >> vecStr[i];
    sort(vecStr.begin(), vecStr.end(), sortStr);
    unordered_set<string> setStr;
    bool ok = true;
    for(string s : vecStr) {
      string tmp = "";
      for(char c : s) {
        tmp += c;
        if(setStr.count(tmp)) ok = false;
      }
      setStr.emplace(s);
    }
    if(ok) cout << "YES" << '\n';
    else cout << "NO" << '\n';
  }
}