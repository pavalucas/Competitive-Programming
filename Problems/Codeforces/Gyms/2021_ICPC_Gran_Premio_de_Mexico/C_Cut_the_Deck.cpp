#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        int count_b = 0, count_r = 0;
        s += s;
        int idx = 0;
        int result = -1;
        while (idx < n) {
            if (s[idx] == 'R') {
                idx++;
                continue;
            }
            count_b = 0, count_r = 0;
            int cur_idx = idx + 1;
            count_b++;
            while (cur_idx < 2*n && count_b >= count_r) {
                if(s[cur_idx] == 'R') count_r++;
                else count_b++;
                cur_idx++;
                if(cur_idx == idx + n) {
                    result = idx;
                    break;
                }
            }
            if (result != -1) break;
            idx = cur_idx;
        }
        cout << result << endl;
    }
    return 0;
}