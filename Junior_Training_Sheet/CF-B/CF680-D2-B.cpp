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
    int n, a;
    cin >> n >> a;
    a--;
    vi thieves(n);
    rp(i,n) cin >> thieves[i];
    int maxDist = max(a, n-1-a);
    WATCH(maxDist);
    int resp = 0;
    rp(i,maxDist+1) {
        if(i == 0) resp += thieves[a];
        else {
            WATCH(a-i);
            WATCH(a+i);
            if(a-i >= 0 && a+i < n) {
                if(thieves[a-i] && thieves[a+i]) resp += 2;
            }
            else if(a+i >= n) {
                WATCH(i);
                resp += thieves[a-i];
            }
            else if(a-i < 0) {
                WATCH(i);
                resp += thieves[a+i];
            }
        }
    }
    cout << resp << '\n';
    return 0;
}