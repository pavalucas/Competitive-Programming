#include <bits/stdc++.h>
using namespace std;

int vec[1001];
int mark[1001];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        vec[i] = --a;
    }

    int resp;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) mark[j] = 0;
        int a = i;
        mark[a] = 1;
        while(true) {
            mark[vec[a]]++;
            if(mark[vec[a]] == 2) {
                cout << vec[a] + 1 << " ";
                break;
            }
            a = vec[a];
        }
    }
    cout << endl;
	return 0;
}