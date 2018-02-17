#include <bits/stdc++.h>
#include <cassert>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define INF 0x3F3F3F3F
#define INFLL 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rp(i, n) for(int i=0; i < int(n); i++)

#define contOnes __builtin_popcountl
#define logLow(X) (X <= 0 ? 0 : 31 - __builtin_clz(X))
#define logUpper(X) (X <= 1 ? 0 : 32 - __builtin_clz(X-1))
#define pow2(X) ((X)*(X))

#define watch(x) cout << (#x) << " is " << (x) << endl
#define mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define unico(x) x.erase(unique(all(x)), (x).end())

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<vd> vvd;

const double inf = 1.0/0.0;
const double pi = 2 * acos(0.0);

#define TRACE(x...) x
#define PRINT(x...)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl )

#define MAXN 100010

// Retorna -1 se a < b, 0 se a = b e 1 se a > b.
int cmp_double(double a, double b = 0, double eps = 1e-9) {
    return a + eps > b ? b + eps > a ? 0 : 1 : -1;
}

struct cmp {
	bool operator()(ii a, ii b) {
		if(a.fi > b.fi) return true;
		else if(a.fi < b.fi) return false;
		else return a.se < b.se;
	}
};

typedef tree<
    ii,
    null_type,
    cmp,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;

int main(void) {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	ordered_set index;
    map<string, int> codeToId;
    map<int, string> idToCode;
    map<int, int> idToRel;
    string s, code;
    int id = 0;
    rp(i, n) {
        cin >> s;
        if(s == "ISSUE") {
            cin >> code;
            if(codeToId.find(code) != codeToId.end()) {
                int id = codeToId[code];
                cout << "EXISTS " << id << " " << idToRel[id] << endl;
            } else {
                cout << "CREATED " << id << " 0" << endl;
                idToRel.insert({id, 0});
                index.insert({0, id});
                idToCode.insert({id, code});
                codeToId.insert({code, id++});
            }
        } else if(s == "DELETE") {
            cin >> code;
            if(codeToId.find(code) != codeToId.end()) {
                int id = codeToId[code];
                int rel = idToRel[id];
                cout << "OK " << id << " " << rel << endl;
                codeToId.erase(code);
                idToCode.erase(id);
                idToRel.erase(id);
                index.erase({rel, id});
            } else {
                cout << "BAD REQUEST" << endl;
            }
        } else if(s == "RELIABILITY") {
            int newRel;
            cin >> code >> newRel;
            if(codeToId.find(code) != codeToId.end()) {
                int id = codeToId[code];
                int rel = idToRel[id];
                cout << "OK " << id << " " << rel + newRel << endl;
                idToRel[id] += newRel;
                index.erase({rel, id});
                index.insert({rel + newRel, id});
            } else {
                cout << "BAD REQUEST" << endl;
            }

        } else {
            int nth;
            cin >> nth;
            if(index.size() > 0) {
                if(nth >= index.size()) nth = index.size() - 1;
                ii chosen = *index.find_by_order(nth);
                string code = idToCode[chosen.se];
                cout << "OK " << code << " " << chosen.se << " " << chosen.fi << endl;
            } else {
                cout << "EMPTY" << endl;
            }
        }
    }

	return 0;
}
