#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> tasks(4, 0);
    for (int i = 0; i < 10; i++) {
        int num;
        cin >> num;
        tasks[num-1]++;
    }
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        if(tasks[i] == 0) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
