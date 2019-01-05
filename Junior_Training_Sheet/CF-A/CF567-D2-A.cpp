#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rp(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep(i, x, n) for (int i = (x); i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)

#define TRACE(x...)
#define PRINT(x...)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl )

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    vi vec(n);
    rp(i,n) cin >> vec[i];
    rp(i,n) {
        int minDist;
        if(i == 0) minDist = abs(vec[i+1] - vec[i]);
        else if(i == n-1) minDist =  abs(vec[i-1] - vec[i]);
        else minDist = min(abs(vec[i+1] - vec[i]), abs(vec[i-1] - vec[i]));

        int maxDist = max(abs(vec[i] - vec[0]), abs(vec[i] - vec[n-1]));

        cout << minDist << " " << maxDist << '\n';
    }
    return 0;
}
