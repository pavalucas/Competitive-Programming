#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n;
    cin >> n;
    ll result = 0, at = 1, sum = 1, cur = 0;
    while(result < n) {
        at++;
        if(cur == 0) {
            result += sum;
        } else {
            result += sum;
            sum++;
        }
        cur = (cur + 1) % 2;
    }
    cout << at << '\n';
    return 0;
}