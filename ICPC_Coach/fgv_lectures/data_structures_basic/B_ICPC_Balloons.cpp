#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        set<char> st;
        int resp = 0;
        for(int i = 0; i < n; i++) {
            if(st.count(s[i]) > 0) {
                resp++;
            } else {
                st.insert(s[i]);
                resp += 2;
            }
        }
        cout << resp << endl;
    }

    return 0;
}