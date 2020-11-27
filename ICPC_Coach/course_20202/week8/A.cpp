#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int MAXN = 200020;
const ll INF = 1e16;
ll dp[MAXN][2];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll n, a, b;
        string s;
        cin >> n >> a >> b >> s;
        s += '0';
        dp[0][0] = b;
        dp[0][1] = INF;
        for(int i = 1; i <= n; i++) {
            if(s[i] == '1' || s[i-1] == '1') dp[i][0] = INF;
            else dp[i][0] = min(dp[i-1][0] + a + b, dp[i-1][1] + 2*a + b);

            dp[i][1] = min(dp[i-1][0] + 2*a + 2*b, dp[i-1][1] + a + 2*b);
        }
        cout << dp[n][0] << endl;
    }
}