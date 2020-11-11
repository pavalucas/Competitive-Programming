#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010

int main(void) {
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s1, s2;
  int n;
  cin >> n;
  cin >> s1 >> s2;
  int resp = 0;
  for(int i = 0; i < n-1; i++) {
      if(s1[i] != s2[i] && s1[i+1] != s2[i+1] && s1[i] == s2[i+1]) {
          char tmp = s1[i];
          s1[i] = s1[i+1];
          s1[i+1] = tmp;
          resp++;
      } else if (s1[i] != s2[i]) {
          resp++;
      }
  }
  if(s1[n-1] != s2[n-1]) resp++;
  cout << resp << endl;
    return 0;
}