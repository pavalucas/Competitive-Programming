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

ll unity[13] = {0};
const ll MOD = 1e9+7;

ll getNumSize(ll a) {
    string s = to_string(a);
    return (ll) s.size();
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n;
    cin >> n;
    vll vec(n);
    rp(i,n) cin >> vec[i];

    rp(i,n) {
        unity[getNumSize(vec[i])+1]++;
    }

    ll resp = 0;
    rp(i,n) {
        ll dec = 1;
        resp = (resp + (vec[i] * (n-1)) % MOD) % MOD;
        rep(j,1,11) {
            WATCH(j);
            WATCH(unity[j]);
            if(unity[j] == 0) {
                dec *= 10;
                continue;
            }
            if(getNumSize(vec[i])+1 == j) resp = (resp + (((vec[i] * dec) % MOD) * (unity[j] - 1)) % MOD) % MOD;
            else resp = (resp + (((vec[i] * dec) % MOD) * unity[j]) % MOD) % MOD;
            dec *= 10;
            WATCH(resp);
        }
    }

    cout << resp << '\n';

    return 0;
}