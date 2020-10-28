#include <bits/stdc++.h>

using namespace std;


bool simulate(long long n, long long k) {
    long long vas = 0;
    long long ini = n;
    while(n > 0) {
        vas += (k > n)? n : k;
        n -= k;
        n -= n/10;
    }
    //cout << vas << endl;
    if(vas >= (ini + ini%2) / 2) {
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long n;
    cin >> n;
    long long low = 1;
    long long high = n;
    while(low < high) {
        long long mid = low + (high - low) / 2;
        if(simulate(n, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << high << endl;
    return 0;
}