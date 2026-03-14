#include <bits/stdc++.h>
using namespace std;

int main() {
    int P, D;
    cin >> P >> D;

    vector<int> stk(P, 0);

    for (int i = 0; i < D; i++) {
        int K;
        cin >> K;
        for (int j = 0; j < K; j++)
            stk[j]++;
        sort(stk.begin(), stk.begin() + K);
    }

    cout << *max_element(stk.begin(), stk.end()) << endl;
    return 0;
}
