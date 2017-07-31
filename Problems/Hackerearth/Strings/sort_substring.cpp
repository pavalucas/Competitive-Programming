#include <bits/stdc++.h>

using namespace std;

#define rp(i, n) for(int i = 0; i < (int)n; i++)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    rp(i, t)
    {
        int a, b;
        string s;
        cin >> s >> a >> b;
        sort(s.begin() + a, s.begin() + b + 1, greater<int>());
        cout << s << endl;
    }
    return 0;
}