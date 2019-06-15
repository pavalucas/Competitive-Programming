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

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    string a, b;
    cin >> a >> b;
    vpi vec(sz(a));
    bool has0 = false, has1 = false, has2 = false;
    rp(i,sz(a)) {
        if(a[i] == '#' && b[i] == '.') {
            vec[i] = mp(0, i);
            has0 = true;
        }
        else if(a[i] == '#' && b[i] == '#') {
            vec[i] = mp(1, i);
            has1 = true;
        }
        else if(a[i] == '.' && b[i] == '#') {
            vec[i] = mp(2, i);
            has2 = true;
        }
        else vec[i] = mp(3, i);
    }

    sort(all(vec));
    string newA = a, newB = b;
    rp(i,sz(a)) {
        newA[i] = a[vec[i].se];
        newB[i] = b[vec[i].se];
    }

    if(has0 && has2 && !has1) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    cout << newA << endl;
    cout << newB << endl;

    return 0;
}