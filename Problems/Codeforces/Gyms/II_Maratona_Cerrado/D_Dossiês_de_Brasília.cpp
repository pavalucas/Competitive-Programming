#include <bits/stdc++.h>
using namespace std;

int calc_size(int n, int i) {
    return n - i;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    pair<char, int> a = make_pair('#', -1);
    pair<char, int> b = make_pair('#', -1);
    for(int i = 0; i < n; i++) {
        char c = s[i];
        if(a.first == '#')
            a = make_pair(c, calc_size(n, i));
        else if(c != a.first && b.first == '#') 
            b = make_pair(c, calc_size(n, i));;
    }

    for(int i = 0; i < q; i++) {
        string t;
        cin >> t;
        int m = t.size();
        int result = max(n, m);
        for(int j = 0; j < m; j++) {
            if(t[j] != a.first) 
                result = max(result, a.second + calc_size(m, j));
            else if(b.first != '#') 
                result = max(result, b.second + calc_size(m, j));
        }
        cout << result << endl;
    }
    return 0;
}