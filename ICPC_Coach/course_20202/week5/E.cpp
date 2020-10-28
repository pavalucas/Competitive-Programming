#include <bits/stdc++.h>

using namespace std;

const string ptt = "welcome to code jam";
constexpr int mod = 10000;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    string tmp;
    getline(cin, tmp);
    for(int c = 1; c <= t; ++c)
    {
        int len = (int) ptt.size();
        vector<int> dp(len + 1, 0);
        dp[0] = 1;

        string x;
        getline(cin, x);
        for(const char& c : x) {
            for(int i = len; i > 0; --i) {
                if(ptt[i - 1] == c) {
                    dp[i] = (dp[i] + dp[i - 1]) % mod;
                }
            }
        }
        int result = dp[len];
        cout << "Case #" << c << ": ";
        string resultStr = "0000";
        resultStr[0] = result / 1000 + '0';
        resultStr[1] = (result % 1000) / 100 + '0';
        resultStr[2] = (result % 100) / 10  + '0';
        resultStr[3] = (result % 10) + '0';
        cout << resultStr << '\n';
    }
    return 0;
}