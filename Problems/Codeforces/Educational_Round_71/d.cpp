#include <bits/stdc++.h>
 
using namespace std;
 
#define TRACE(x...)
#define WATCH(x) TRACE( cout << #x" = " << x << endl)
#define PRINT(x) TRACE(printf(x))
#define WATCHR(a, b) TRACE( for(auto c = a; c != b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end()); } )
 
const int MOD = 998244353;
const int MAXN = int(3e5) + 20;

int sum(int a, int b) {
	return (a + b) % MOD;
}

int mul(int a, int b) {
    return (a * 1LL * b) % MOD;
}
 
int fac(int n) {
    int resp = 1;
    for(int i = 1; i <= n; i++) {
        resp = mul(resp, i);
    }
    return resp;
}
 
int n;
pair<int, int> vec[MAXN];
int countNumA[MAXN];
int countNumB[MAXN];
map<pair<int, int>, int> countNumAB;
 
bool checkDoubleSort() {
    for(int i = 1; i < n; i++) {
        if(vec[i].first < vec[i-1].first || vec[i].second < vec[i-1].second) return false;
    }
    return true;
}
 
int main(void) {
    scanf("%d", &n);
 
    for(int i = 0; i < n; i++) scanf("%d%d", &vec[i].first, &vec[i].second);
 
    int resp = fac(n);
 
    for(int i = 0; i < n; i++) {
        countNumA[vec[i].first]++;
        countNumB[vec[i].second]++;
        countNumAB[vec[i]]++;
        WATCH(countNumB[vec[i].second]);
    }
 
    sort(vec, vec + n);
 
    WATCH(resp);
 
    int countA = 1, countB = 1;
    for(int i = 1; i <= n; i++) {
        countA = mul(countA, fac(countNumA[i]));
        countB = mul(countB, fac(countNumB[i]));
    }
 
 	WATCH(countA);
    WATCH(countB);
 
 	resp = sum(resp, MOD - countA);
 	resp = sum(resp, MOD - countB);
 
    if(checkDoubleSort()) {
        int countAB = 1;
        for(auto& p : countNumAB) {
            countAB = mul(countAB, fac(p.second));
        }
        WATCH(countAB);
        resp = sum(resp, countAB);
    }
 
    cout << resp << endl;
    return 0;
}
