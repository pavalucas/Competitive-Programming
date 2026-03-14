#include <bits/stdc++.h>
using namespace std;

vector<int> d(2*1e5 + 10);
int main()
{
    int n, x, y, lastX, lastY;
    cin >> n;
    cin >> lastX >> lastY;
    for(int i = 1; i < n; i++) {
        cin >> x >> y;
        int tmp = abs(x - lastX) + abs(y - lastY);
        lastX = x;
        lastY = y;
        d[i-1] = tmp;
    }
    int valMin = 0;
    int valMax = 2*1e9;
    int sum = 0;
    for(int i = 0; i < n-1; i++) {
        if(i % 2 == 0) {
            sum += d[i];
            valMax = min(valMax, sum);
        } else {
            sum -= d[i];
            valMin = max(valMin, sum);
            }
    }
    if(valMax - valMin >= 2 and valMax - 1 > 0) {
        cout << valMax - 1 << endl;
    } else {
        cout << -1 << endl;
    }
    

    return 0;
}