#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long sum[3] = {0, 0, 0};
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum[0] += a;
    }
    for (int i = 0; i < n-1; i++) {
        int a;
        cin >> a;
        sum[1] += a;
    }
    for (int i = 0; i < n-2; i++) {
        int a;
        cin >> a;
        sum[2] += a;
    }
    cout << sum[0] - sum[1] << endl;
    cout << sum[1] - sum[2] << endl;
}