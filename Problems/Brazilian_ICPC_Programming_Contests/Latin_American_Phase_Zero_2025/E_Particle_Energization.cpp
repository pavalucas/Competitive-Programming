#include<bits/stdc++.h>
using namespace std;

vector<long long> p;
long long y, k;

void add_div() {
    long long aux = y;
    for(long long i = 2; i*i <= aux; i++) {
        while(aux % i == 0) {
            p.push_back(i);
            aux /= i;
        }
    }
    if(aux > 1) {
        p.push_back(aux);
    }
}

int main()
{
    cin >> y >> k;
    add_div();
    long long resp = 1;
    for(auto& d : p) {
        // cout << "div: " << d << endl;
        if(k - d + 1 <= 0) {
            resp *= (k + 1);
            k = 0;
            break;
        }
        k -= (d - 1);
        resp *= d;
        // cout << "k: " << k << endl;
        // cout << "resp: " << resp << endl;
    }
    if(k > 0) {
        resp *= (k + 1);
    }
    cout << resp << endl;
    return 0;
}