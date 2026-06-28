#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int interv[2];
    interv[0] = 2*60;
    interv[1] = 12*60;
    int cur = 0;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        cur += t;
        for(int j = 0; j < 2; j++) {
            if(cur > interv[j] and cur <= interv[j] + 3*60) {
                cur += 3*60;
            }
        }
    }
    cout << cur << endl;

    return 0;
}