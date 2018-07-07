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
    map<string, int> freq;
    string s;
    cin >> n;
    cin >> s;
    rp(i, n-1) {
        string tmp = "";
        tmp += s[i];
        tmp += s[i+1];
        if(freq.find(tmp) != freq.end()) {
            freq[tmp]++;
        } else {
            freq.insert(mp(tmp, 1));
        }
    }

    string resp;
    int maxVal = -1;
    for(auto& p : freq) {
        if(p.se > maxVal) {
            resp = p.fi;
            maxVal = p.se;
        }
    }
    cout << resp << endl;
    return 0;
}
