#include <bits/stdc++.h>

using namespace std;

int n, x;
vector<pair<int, int>> blow(110);

int initCheck() {
    int maxDiff = 0;
    for(int i = 0; i < n; i++) {
        maxDiff = max(maxDiff, blow[i].first - blow[i].second);
    }
    return maxDiff;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> x;
        for(int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            blow[i] = {a, b};
        }
        sort(blow.begin(), blow.begin() + n);
        int maxBlow = blow[n-1].first;
        x -= maxBlow;
        if(x <= 0) {
            cout << 1 << '\n';
        } else {
            int maxDiff = initCheck();
            if(maxDiff == 0) cout << -1 << '\n';
            else {
                int resp = 1;
                if(x % maxDiff == 0) resp += x / maxDiff;
                else resp += x / maxDiff + 1;
                cout << resp << endl;
            }
        }
    }
    return 0;
}