#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x;
    cin >> x;
    long long result = 0;
    for(int i = 1; i <= x; i++) {
        result += i;
    }
    cout << 2 * x + result << endl;
    return 0;
}