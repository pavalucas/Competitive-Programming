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

vvi arr(1001);
vi arrInput;
int n;

void printQuery(int ini, int end, int& val) {
    cout << "? ";
    cout << n << " ";
    rep(i,ini,end) {
        cout << val << " ";
        if(i%2) val++;
    }
    cout << endl;
    cout.flush();
}

void readInput() {
    int k;
    cin >> k;
    rp(i,k) {
        int a;
        cin >> a;
        arrInput.pb(a);
    }
}
void getArr(int& pos, int& curSize) {
    set<int> curSet;
    vi curArr;
    for(auto& a : arrInput) {
        WATCH(curSize);
        if(curSet.find(a) != curSet.end()) {
            curSize = curSet.size();
            for(auto p : curArr) arr[pos].pb(p);
            pos++;
            curSet.clear();
            curArr.clear();
        } else if(curSize == 0) {
            curSet.insert(a);
            curArr.pb(a);
        }

        if(curSize > 0) curSize--;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;

    int val = 1;
    printQuery(0,n,val);

    readInput();

    printQuery(n,2*n,val);

    readInput();

    int pos = 0, curSize = 0;
    getArr(pos, curSize);

    cout << "! ";
    rp(i,n) {
        cout << sz(arr[i]) << " ";
        for(auto p : arr[i]) cout << p << " ";
    }
    cout << endl;
    return 0;
}