#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll d, m;
    cin >> d >> m;
    if (m > d) d ^= m ^= d ^= m;

    if (d > 12 || d == m)
        cout << "DATA SEGURA" << endl;
    else
        cout << "DATA INCERTA" << endl;

    return 0;
}