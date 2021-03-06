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
const int VAL = 2*1e7;
const int MAXN = 1e3 + 10;

int n, k;
vvi rid(MAXN);
vi vecA(MAXN);
vi vecB(MAXN);
vi ridSkill(MAXN);

void calcRid() {
    rp(i,k) {
        rp(j,n) {
            rid[i].pb(3*vecA[i]*vecA[i] + 5*vecA[i]*vecB[j]
             + 2*vecB[j]*vecB[j]);
        }
        sort(all(rid[i]), greater<int>());
    }
}

int main()
{
    ifstream in("competitions.in");
    ofstream out("competitions.out");
    in >> n >> k;
    vector<tuple<ll, ll, ll> > timeCompet(n);
    rp(i,n) {
        int a, b, c;
        in >> a >> b >> c;
        ridSkill[i] = b;
        timeCompet[i] = make_tuple(VAL - a, -c, i);
    }

    rp(i,k) in >> vecA[i];
    rp(i,n) in >> vecB[i];

    calcRid();

    sort(all(timeCompet));

    rp(i,k) {
        rp(j,n) {
            ll& val = get<0>(timeCompet[j]);
            ll curIndex = get<2>(timeCompet[j]);
            val += (VAL - ridSkill[curIndex] - rid[i][j]);
        }
        sort(all(timeCompet));
    }

    rp(i,n) {
        out << get<2>(timeCompet[i]) + 1 << " ";
    }
    out << '\n';


    return 0;
}