/* Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/2134 */

#include <bits/stdc++.h>

using namespace std;

#define rp(i, n) for(int i = 0; i < (int)n; ++i)
#define pb push_back
#define se second
#define fi first
#define mp make_pair
#define all(x) (x).begin(), (x).end()

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, t = 1;
    while(cin >> n)
    {
        vector<pair<int, string>> vec(n);
        rp(i, n)
        {
            string a;
            int b;
            cin >> a >> b;
            vec[i] = mp(b, a);
        }
        sort(all(vec));
        pair<int, string> resp = vec[0];
        int i = 1;
        while(i < vec.size() && vec[i].fi == resp.fi)
        {
            resp.se = vec[i++].se;
        }

        cout << "Instancia " << t++ << endl;
        cout << resp.se << endl << endl;
    }
}