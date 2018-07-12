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


queue<ull> q1;
queue<ull> q2;
vector<ull> query(1000010);
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m;
    cin >> n >> m;
	vector<ull> vet(n);
    rp(i,n) cin >> vet[i];
    sort(vet.rbegin(), vet.rend());
    rp(i,n) q1.push(vet[i]);
    rp(i,m) cin >> query[i];
    int j = 0;
    ull a, b;
    for(int i = 1; i <= query[m-1]; i++) {
    	ull maxEle = 0;
    	ull resp;
    	if(!q1.empty() && !q2.empty()) {
    		a = q1.front();
    		b = q2.front();
    		if(a >= b) {
    			q1.pop();
    			resp = a;
    			if(a/2 > 0) q2.push(a/2);
    		} else {
    			q2.pop();
    			resp = b;
    			if(b/2 > 0) q2.push(b/2);
    		}
    	} else if(!q1.empty()) {
    		a = q1.front();
    		resp = a;
    		q1.pop();
    		if(a/2 > 0) q2.push(a/2);
    	} else {
    		b = q2.front();
    		resp = b;
    		q2.pop();
    		if(b/2 > 0) q1.push(b/2);
    	}
    	if(i == query[j]) {
    		cout << resp << endl;
    		j++;
    	}
    }
    return 0;
}