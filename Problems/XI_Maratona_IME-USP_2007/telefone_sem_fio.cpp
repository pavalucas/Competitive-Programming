/* Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1448 */

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    for(int t = 1; t <= n; t++)
    {
        string corr, time1, time2;
        int f1 = -1, f2 = -1, pt1 = 0, pt2 = 0;
        if(t == 1) getline(cin, corr);
        getline(cin, corr);
        getline(cin, time1);
        getline(cin, time2);
        for(int i = 0; i < corr.size(); i++)
        {
            if(corr[i] == time1[i])
            {
                pt1++;
                if(f1 == -1 && corr[i] != time2[i])
                    f1 = i;
            }
            if(corr[i] == time2[i])
            {
                pt2++;
                if(f2 == -1 && corr[i] != time1[i])
                    f2 = i;
            }
        }
        cout << "Instancia " << t << endl;
        if(pt1 > pt2)
            cout << "time 1" << endl;
        else if(pt2 > pt1)
            cout << "time 2" << endl;
        else
        {
            if(f1 > f2)
                cout << "time 2" << endl;
            else if(f2 > f1)
                cout << "time 1" << endl;
            else
                cout << "empate" << endl;
        }
        cout << endl;
    }
    return 0;
}