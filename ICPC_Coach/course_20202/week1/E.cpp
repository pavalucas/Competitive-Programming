#include <bits/stdc++.h>

using namespace std;

int main() {
  int test;
  cin >> test;
  for(int t = 1; t <= test; t++) {
    int a, b;
    cin >> a >> b;
    int sum = 0;
    for(int i = a; i <= b; i++) {
      if(i % 2) sum += i;
    }
    cout << "Case " << t << ": " << sum << '\n';
  }
}