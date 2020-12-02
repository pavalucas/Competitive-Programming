#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll lcm(ll a, ll b) {
    if (a == 0 && b == 0) return 0;
    return a / __gcd(a,b) * b;
}

int main() {
  ll x;
  cin >> x;
  ll result = 1;
  for(ll i = 1; i * i <= x; i++) {
    if(x % i == 0 && lcm(i, x / i) == x) {
      result = i;
    }
  }
  cout << result << " " << x / result << '\n';

}