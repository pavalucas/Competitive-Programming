#include <bits/stdc++.h>
using namespace std;

template <typename T>
T gcd(T a, T b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    int val = -1;
    vector<int> vec;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        vec.push_back(a);
        if(val < 0) val = a;
        val = gcd(val, a);
    }
    long long resp = 0;
    for(auto& a : vec) {
        resp += a / val;
    }
    cout << resp << endl;
    return 0;
}