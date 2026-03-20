#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, int> m;
    vector<pair<string, int>> m2;
    while(n--)
    {
        string s;
        int a;
        cin >> s >> a;
        m[s] += a;
        m2.push_back({s, m[s]});
    }
    int max_val = 0;
    for(auto i : m) {
        max_val = max(max_val, i.second);
    }
    set<string> winners;
    for(auto i : m) {
        if(i.second == max_val) {
            winners.insert(i.first);
        }
    }
    for(auto i : m2) {
        if(winners.count(i.first) && i.second >= max_val) {
            cout << i.first << endl;
            break;
        }
    }

    return 0;
}