/* Link: https://www.hackerrank.com/challenges/hackerrank-in-a-string/problem */

#include <bits/stdc++.h>

using namespace std;

#define rp(i, n) for(int i = 0; i < (int)n; i++)

string hack = "hackerrank";
bool checkHack(string& s)
{
    int j = 0;
    for(auto c : s)
    {
        if(c == hack[j])
            j++;
        if(j == hack.size())
            return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    rp(i, n)
    {
        string s;
        cin >> s;
        if(checkHack(s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

}