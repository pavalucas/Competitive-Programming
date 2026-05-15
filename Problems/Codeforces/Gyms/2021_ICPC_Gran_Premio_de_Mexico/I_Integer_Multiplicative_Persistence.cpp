#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int count = 0;
        while (n >= 10) {
            int product = 1;
            while (n > 0) {
                product *= n % 10;
                n /= 10;
            }
            n = product;
            count++;
        }
        cout << count << endl;
    }
    return 0;
}