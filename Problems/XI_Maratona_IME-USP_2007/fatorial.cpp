/* Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/2129 */

#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back

int dig[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};

int lastNon0Digit(int n)
{
     if (n < 10)
        return dig[n];

    if (((n/10)%10)%2 == 0)
        return (6*lastNon0Digit(n/5)*dig[n%10]) % 10;
    else
        return (4*lastNon0Digit(n/5)*dig[n%10]) % 10;
}

main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 0, n;
    while(cin >> n){
        cout << "Instancia " << ++t << endl << lastNon0Digit(n) << endl << endl;
    }
}
