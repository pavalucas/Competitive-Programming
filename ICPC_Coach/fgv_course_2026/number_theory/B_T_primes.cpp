#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        long long root = sqrt(x);
        if (root * root == x and root > 1) {
            bool is_prime = true;
            for (long long j = 2; j * j <= root; j++) {
                if (root % j == 0) {
                    is_prime = false;
                    break;
                }
            }
            cout << (is_prime ? "YES" : "NO") << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}