#include <bits/stdc++.h>

using namespace std;
int N = 1e5 + 10;
vector<int> a(2*N);
vector<int> b(2*N);
map<int, int> countA;
map<int, int> countB;
int n;

void countCont(vector<int>& arr, map<int, int>& countArr) {
    if(arr.size() == 0) {
        return;
    } 
    int count = 1;
    int cur = arr[0];
    countArr[cur] = 1;
    for(int i = 1; i < n; i++) {
        countArr[cur] = max(countArr[cur], count);
        if(arr[i] == cur) {
            count++;
        } else {
            count = 1;
            cur = arr[i];
        }
    }
    countArr[cur] = max(countArr[cur], count);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        
        for(int i = 0; i < 2 * n + 1; i++) {
            countA[i] = 0;
            countB[i] = 0;
        }
        
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        countCont(a, countA);
        countCont(b, countB);
        int res = 0;
        
        for(int i = 0; i < 2 * n + 1; i++) {
            res = max(res, countA[i] + countB[i]);
        }
        cout << res;
        cout << "\n";
    }
}