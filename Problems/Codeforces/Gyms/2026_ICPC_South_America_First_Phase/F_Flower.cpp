#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7 + 10;
vector<int> f(MAXN, 0), inv(MAXN, 0);

int main() {
    int n;
    cin >> n;
    f[1] = 2;
    inv[2] = 1;
    for(int i = 2; i <= n; i++) {
        if(inv[i]) 
            f[i] = 3*inv[i];
        else
            f[i] = f[i-1] + 1;

        if(f[i] <= n) 
            inv[f[i]] = i; 
    }
    cout << f[n] << endl;
}