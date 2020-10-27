#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int b, p, f, h, c;
        cin >> b >> p >> f >> h >> c;
        int resp = 0;
        if(h >= c) {
            while(p > 0 && b > 1) {
                p--;
                b-=2;
                resp += h;
            }
            while(f > 0 && b > 1) {
                f--;
                b-=2;
                resp += c;
            }
        } else {
            while(f > 0 && b > 1) {
                f--;
                b-=2;
                resp += c;
            }
            while(p > 0 && b > 1) {
                p--;
                b-=2;
                resp += h;
            }
        }
        cout << resp << endl;
    }
    return 0;
}