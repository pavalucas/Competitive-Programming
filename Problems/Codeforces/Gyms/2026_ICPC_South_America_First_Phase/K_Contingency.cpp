#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> c(n);
    vector<int> k(n);
    int allStock = 0;
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        allStock += c[i];
    }
    int minC = 2*10e9;
    int minDiff = 2*10e9;
    int minIdx = -1;
    for(int i = 0; i < n; i++) {
        cin >> k[i];
        int diff = c[i] - k[i];
        if(diff >= 0 && diff < minDiff)  {
            minDiff = diff;
            minIdx = i;
        }
        
    }
    
    for(int i = 0; i < n; i++) {
        if(k[i] > c[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    cout << allStock - c[minIdx] + k[minIdx] << endl;

    return 0;
}