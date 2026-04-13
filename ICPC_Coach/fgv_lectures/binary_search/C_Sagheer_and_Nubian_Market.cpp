#include <bits/stdc++.h>
using namespace std;

int n, s;
long long can(int mid, const vector<int>& a) {
    long long sum = 0;
    vector<int> temp(n);
    for (int i = 0; i < n; i++) {
        temp[i] = a[i] + (i + 1) * mid;
    }
    sort(temp.begin(), temp.end());
    for (int i = 0; i < mid; i++) {
        sum += temp[i];
    }
    if (sum > s) {
        return -1;
    }
    return sum;
}

int main() {
    
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int lo = 0, hi = n;
    long long sum = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        long long result = can(mid, a);
        if (result >= 0) {
            lo = mid + 1;
            sum = result;
        } else {
            hi = mid - 1;
        }
    }
    cout << hi << " " << sum << endl;
        
    return 0;
}