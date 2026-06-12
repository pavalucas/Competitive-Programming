#include <bits/stdc++.h>

using namespace std;

int vec[5010];
int mark[5010] = {0};

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> vec[i];
        vec[i]--;
    }
    for(int i = 0; i < n; i++) {
        int dist = 0;
        int at = i;
        mark[i] = 1;
        while(mark[vec[at]] == 0) {
            at = vec[at];
            mark[at] = 1;
            dist++;
        }
        if(dist + 1 == 3 && vec[at] == i) {
            cout << "YES" << endl;
            return 0;
        }
        for(int i = 0; i < n; i++) mark[i] = 0;
    }
    cout << "NO" << endl;
    return 0;
}