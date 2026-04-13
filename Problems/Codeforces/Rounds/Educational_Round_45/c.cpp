#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rp(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)

#define TRACE(x...)
#define PRINT(x...)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl )

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;

vector<string> vec(300010);

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n;
    cin >> n;
    map<pii, ll> braMap;
    rp(i,n) {
        cin >> vec[i];
        ll le = 0, ri = 0;
        for(char c : vec[i]) {
            if(c == '(') le++;
            else {
                if(le > 0) le--;
                else ri++;
            }
        }
        pii tmp = mp(le, ri);
        if(braMap.find(tmp) != braMap.end()) {
            braMap[tmp]++;
        } else {
            braMap.insert(mp(tmp, 1));
        }
    }

    ll resp = 0;
    for(auto& p : braMap) {
        if(p.fi.fi > 0 && p.fi.se == 0) {
            pii tmp = mp(0, p.fi.fi);
            if(braMap.find(tmp) != braMap.end()) {
                resp += braMap[p.fi] * braMap[tmp];
            }
        } else if(p.fi.fi == 0 && p.fi.se == 0) {
            resp += braMap[p.fi] * braMap[p.fi];
        }
    }

    cout << resp << endl;
    return 0;
}
