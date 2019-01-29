#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rp(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep(i, x, n) for (int i = (x); i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)

#define TRACE(x...)
#define WATCH(x) TRACE( cout << #x" = " << x << endl)
#define PRINT(x) TRACE(printf(x))
#define WATCHR(a, b) TRACE( for(auto c = a; c != b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end()); } )

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll lcm(ll a, ll b) {
    if (a == 0 && b == 0) return 0;
    return a / __gcd(a,b) * b;
}

int main()
{
    ll n;
    cin >> n;

    ll resp = 0;
    // we want to find for each "i", how many numbers "i" is the second non divisor
    // i and j are the non divisors
    for(ll i = 3; i <= 30; i++) {
        for(ll j = 2; j <= i-1; j++) {
            ll lcmA = 1;
            for(ll k = 2; k < i; k++) {
                if(k != j) lcmA = lcm(lcmA, k);
            }
            WATCH(lcmA);
            // how many are divided by 2 to i-1, excluding j
            ll a = n / lcmA;

            // how many are divided by 2 to i, excluding j
            ll b = n / lcm(lcmA, i);

            // how many are divided by 2 to i-1
            ll c = n / lcm(lcmA, j);

            // how many are divided by 2 to i
            ll d = n / lcm(lcm(lcmA, i), j);

            // inclusion exclusion rule to get all that are not divided by i and j
            // and divided by others
            resp += (a - b - c + d) * i;
        }
    }

    cout << resp << '\n';

    return 0;
}