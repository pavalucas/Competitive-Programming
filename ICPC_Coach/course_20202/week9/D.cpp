#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;

ll power(ll b, ll e, ll mod = MOD) {
    ll ret = 1;
    b = b % mod;
    while (e > 0) {
        if (e & 1) ret = (ret * b) % mod;
        e >>= 1;
        b = (b * b) % mod;
    }
    return ret;
}

int main() {
  int n, m;
  cin >> n >> m;
  ll val = power(2, m) - 1;
  ll result = power(val, n);
  cout << result << '\n';
}