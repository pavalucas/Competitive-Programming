#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(2*c < d || 2*d < c || 2*d >= 2*b) {
        cout << -1 << endl;
    } else {
        cout << 2*a << endl;
        cout << 2*b << endl;
        cout << max(c,d) << endl;
    }
    return 0;
}