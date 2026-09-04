#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> num(n), den(n);
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        num[i] = a - b;
        den[i] = a + b;
        if(i > 0) {
            num[i] += num[i-1];
            den[i] += den[i-1];
        }
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int tmp;
        cin >> tmp;
        tmp--;
        if(num[tmp] > 0) {
            cout << "COMPRA";
        } else if(num[tmp] < 0) {
            cout << "VENDA";
        } else {
            cout << "NEUTRO";
        }
        cout << endl;
    }

    return 0;
}