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
    int n;
    cin >> n;
    vi vec(n);
    rp(i,n) cin >> vec[i];
    int resp = 0;
    map<int, int> forb;
    int lastIndex = n;
    rp(i,n) {
        if(vec[i] < 0) {
            forb[-vec[i]]++;
            resp++;
        } else {
            if(forb[vec[i]]) {
                lastIndex = i;
                break;
            } else {
                resp++;
            }
        }
    }
    cout << resp << " ";
    for(int i = 1; i < n; i++) {
        resp--;
        if(vec[i-1] < 0) {
            forb[-vec[i-1]]--;
            while(lastIndex < n) {
               if(vec[lastIndex] < 0) {
                    forb[-vec[lastIndex]]++;
                    resp++;
                } else {
                    if(forb[vec[lastIndex]]) {
                        break;
                    } else {
                        resp++;
                    }
                }
                lastIndex++;
            }
        }
        cout << resp << " ";
    }
    cout << endl;
    return 0;
}