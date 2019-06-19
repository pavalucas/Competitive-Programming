#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<pair<int, int> > people(n);
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        people[i] = {a, b};
    }
    int count = 0;
    for(int i = n; i >= 1; i--) {
        count = 0;
        for(int j = 0; j < n; j++) {
            if(i >= people[j].first && i <= people[j].second) count++;
        }
        if(count == i) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}