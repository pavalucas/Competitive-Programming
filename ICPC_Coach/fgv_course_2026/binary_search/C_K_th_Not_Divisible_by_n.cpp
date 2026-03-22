#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        long long low = 1, high = 2e18;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long count = mid - mid / n;
            if (count < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << low << endl;
    }
}