#include <bits/stdc++.h>

using namespace std;

int n;
int damaged[11];
int reserve[11];
int result = INT_MAX;

void generate(int at, int minKay) {
  if(at == n) {
    // cout << "MinKay: " << minKay << '\n';
    result = min(result, minKay);
    return;
  }
  if(damaged[at]) {
    if(at - 1 >= 0 && reserve[at-1]) {
      // cout << "caso 1 at: " << at << '\n';
      damaged[at] = 0;
      reserve[at-1] = 0;
      generate(at+1, minKay);
      damaged[at] = 1;
      reserve[at-1] = 1;
    } else if(at + 1 < n && reserve[at+1]) {
      // cout << "caso 2 at: " << at << '\n';
      damaged[at] = 0;
      reserve[at+1] = 0;
      generate(at+1, minKay);
      damaged[at] = 1;
      reserve[at+1] = 1;
    }
    generate(at+1, minKay+1);
  } else {
    generate(at+1, minKay);
  }
}

int main() {
  int s, r;
  cin >> n >> s >> r;
  for(int i = 0; i < s; i++) {
    int a;
    cin >> a;
    a--;
    damaged[a] = 1;
  }
  for(int i = 0; i < r; i++) {
    int a;
    cin >> a;
    a--;
    reserve[a] = 1;
    if(reserve[a] && damaged[a]) {
      reserve[a] = 0;
      damaged[a] = 0;
    }
  }
  generate(0, 0);
  cout << result << '\n';
}