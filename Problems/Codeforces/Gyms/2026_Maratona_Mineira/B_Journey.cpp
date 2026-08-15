#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        int steps = 3 * (n / (a + b + c));
        int remain = n % (a + b + c);
        if(remain > 0) {
            if(remain <= a) steps++;
            else if (remain <= a + b) steps += 2;
            else steps += 3;
        }
        cout << steps << endl;
    }
    return 0;
}