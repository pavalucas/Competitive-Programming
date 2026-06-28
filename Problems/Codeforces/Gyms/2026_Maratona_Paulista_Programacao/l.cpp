#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

#ifdef DEBUG
#define trace(u) u
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

#define debug(u) trace(cout << #u " = " << u << ln)
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

vector<vll> dp;
vll perm;
ll n;

// B is INCLUSIVE
ll solve(ll a, ll b) {
    if (a <0 || b < 0) return 0;
    if (b <= a) return dp[a][b] = 0;
    if (dp[a][b] != -1ll) return dp[a][b];

    string s(b-a+1, 'D');
    vll pos(b-a+1, -1);
    ll used = 0;
    forn(i, 0, n) {
        if (perm[i] >= a && perm[i] <= b) {
            pos[perm[i] - a] = used++;
        }
    }

    ll sum = 0;
    s[pos[0]] = '0';
    ll maxp = 0;
    forn(i, 0, b-a) {
        maxp = max(maxp, solve(a, a+i-1) + solve(a+i+1, b) + sum);
        s[pos[i]] = 'E';
        char left = (pos[i] > 0) ? s[pos[i]-1] : 'X';
        char right = (pos[i] < sz(s) - 1) ? s[pos[i]+1] : 'X';
        if (left == 'D' && right != 'E') sum++;
        if (left != 'E' && right == 'D') sum++;

        s[pos[i+1]] = '0';

        left = (pos[i+1] > 0) ? s[pos[i+1]-1] : 'X'; 
        right = (pos[i+1] < sz(s) - 1) ? s[pos[i+1]+1] : 'X'; 
        if (left == 'E' && right != 'D') sum--;
        if (left != 'D' && right == 'E') sum--;
    }
    maxp = max(maxp, solve(a, b-1));
    return dp[a][b] = maxp;
}

int main() {
    _;
    cin >> n;
    perm.resize(n);
    forn(i, 0, n) {
        cin >> perm[i];
    }
    dp.assign(n, vll(n, -1));
    
    cout << solve(0, n - 1) << ln;
    return 0;
}
