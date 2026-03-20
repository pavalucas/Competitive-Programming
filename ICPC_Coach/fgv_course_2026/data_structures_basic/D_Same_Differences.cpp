#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            mp[a-i]++;
        }
        long long ans = 0;
        for (auto it : mp) {
            ans += (long long)(it.second) * (it.second - 1) / 2;
        }
        cout << ans << endl;
    }
    return 0;
}