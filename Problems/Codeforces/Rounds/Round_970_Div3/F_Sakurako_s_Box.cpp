#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll extGcd (ll a , ll b , ll& x , ll& y ) {
    if (b == 0) {
        x = 1 ; y = 0 ; return a ;
    }
    else {
        ll g = extGcd (b , a % b , y , x) ;
        y -= a / b * x ; return g;
    }
}
ll modInv (ll a , ll m) {
    ll x , y ;
    extGcd(a, m, x, y);
    return (x % m + m) % m;
}


int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll result = 0;
        ll sum = a[n-1];
        ll q = (n * (n-1)) / 2;
        for(int i = n - 2; i >= 0; i--) {
            result = (result + (a[i] * sum) % MOD) % MOD;
            sum = (sum + a[i]) % MOD;

        }
        // cout << q << endl;
        ll q_1 = modInv(q, MOD);
        // cout << q_1 << endl;
        cout << (result * q_1) % MOD << endl;
    }
    return 0;
}