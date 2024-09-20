#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        // check if n is square or not
        int root = sqrt(n);
        if(root*root != n) {
            cout << "No" << endl;
            continue;
        }
        bool ok = true;
        for(int i = 0; i < root; i++) {
            for(int j = 0; j < root; j++) {
                int idx =  i * root + j;
                if(i == 0 || j == 0 || i == root - 1 || j == root - 1) {
                    if(s[idx] == '0') {
                        ok = false;
                    }
                } else {
                    if(s[idx] == '1') {
                        ok = false;
                    }
                }
            }
        }
        if(ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}