/* Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/2135 */

#include <bits/stdc++.h>

using namespace std;
#define rp(i, n) for(int i = 0; i < (int)n; ++i)

int findAns(vector<int>& vec)
{
    rp(i, vec.size())
    {
        int sum = 0;
        rp(j, i)
            sum += vec[j];
        if(sum == vec[i]) return vec[i];
    }
    return -1000;
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, t = 1;
    while(cin >> n)
    {
        vector<int> vec(n);
        rp(i, n)
        {
            cin >> vec[i];
        }

        int resp = findAns(vec);

        cout << "Instancia " << t++ << endl;
        if(resp == -1000)
            cout << "nao achei" << endl;
        else
            cout << resp << endl;
        cout << endl;
    }
}