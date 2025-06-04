#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a == 1) {
        cout << "vivo e morto" << endl;
    } else if (b == 0) {
        cout << "morto"<< endl;
    } else {
        cout << "vivo" << endl;
    }

    return 0;
}