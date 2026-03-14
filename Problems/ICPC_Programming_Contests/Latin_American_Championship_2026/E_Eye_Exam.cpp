#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int lo = 1, hi = 1e9;
    for (int i = 0; i < n; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        if (c == 'A') {
            int new_hi = (a + b) / 2 - !((a + b) % 2);
            hi = min(hi, new_hi);
        } else if (c == 'B') {
            int new_lo = (a + b) / 2 + 1;
            lo = max(lo, new_lo);
        } else {
            if((a + b) % 2 == 0) {
                lo = max(lo, (a + b) / 2);
                hi = min(hi, (a + b) / 2);
            } else {
                cout << "*\n";
                return 0;
            }
        }
    }

    if (lo > hi) {
        cout << "*\n";
    } else {
        cout << lo << " " << hi << "\n";
    }

    return 0;
}