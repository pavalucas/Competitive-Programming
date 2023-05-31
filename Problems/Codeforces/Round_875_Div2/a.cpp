#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for(int i = 0; i < n; i++) {
            cin >> p[i];
        }
        for(int i = 0; i < n; i++) {
            cout << n - p[i] + 1 << " ";
        }
        cout << "\n";
    }
}