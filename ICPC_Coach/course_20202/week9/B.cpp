#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  ll d;
  cin >> d;
  unordered_set<ll> numSet;
  ll n1 = -1, n2 = -1;
  for(ll i = 0; i < 1e5 + 1; i++) {
    ll val = i * i;
    if(numSet.count(val)) {
      n1 = (int)sqrt(val - d);
      n2 = i;
      break;
    }
    numSet.emplace(val + d);
  }
  if(n1 == -1) cout << "impossible\n";
  else cout << n1 << " " << n2 << '\n';
}