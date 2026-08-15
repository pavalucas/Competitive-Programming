#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll n;
    ll mod = 1000000007;
    
    ll value = 0;
    ll add = 0;
    ll mult = 1;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char op;
        ll val;
        cin >> op >> val;

        if (op == '+')
            add += val;
        else if (op == '*')
        {
            mult = (mult * val) % mod;
            add = (add * val) % mod;
        }
        if (op == '?')
            cout << ((val * mult) % mod + add) % mod << endl;
        value = value % mod;

    }

    return 0;
}
