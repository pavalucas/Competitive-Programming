#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << max(a/7 * b, b/7 * a) << endl;
    return 0;
}