#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = (int) s.size();
  int pol1 = 0, pol2 = 0, pol3 = 0;
  char polChar1 = 'U', polChar2 = 'D';
  char cur = s[0];
  for(int i = 1; i < n; i++) {
    if(cur != polChar1) {
      pol1++;
    } else if(s[i] != polChar1) {
      pol1 += 2;
    }
    cur = polChar1;
  }

  cur = s[0];
  for(int i = 1; i < n; i++) {
    if(cur != polChar2) {
      pol2++;
    } else if(s[i] != polChar2) {
      pol2 += 2;
    }
    cur = polChar2;
  }

  cur = s[0];
  for(int i = 1; i < n; i++) {
    if(s[i] != cur) {
      pol3++;
    }
    cur = s[i];
  }

  cout << pol1 << '\n' << pol2 << '\n' << pol3 << '\n';
}