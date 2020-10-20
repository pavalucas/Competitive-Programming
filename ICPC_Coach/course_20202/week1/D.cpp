#include <bits/stdc++.h>

using namespace std;

int main() {
  int test;
  cin >> test;
  for(int t = 1; t <= test; t++) {
    string s;
    cin >> s;
    int n = (int) s.size();
    int sum = 0;
    int iniPos = 0, endPos = n-1;
    while(s[iniPos] == '0') iniPos++;
    while(s[endPos] == '0') endPos--;
    for(int i = iniPos; i <= endPos; i++) {
      if(s[i] == '0') sum++;
    }
    cout << sum << '\n';
  }
}
