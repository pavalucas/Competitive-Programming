#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    vector<int> shops(n);
    for(int i = 0; i < n; i++) cin >> shops[i];
    sort(shops.begin(), shops.end());
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int a;
        cin >> a;
        int pos = upper_bound(shops.begin(), shops.end(), a) - shops.begin();
        cout << pos << endl;
    }

    return 0;
}