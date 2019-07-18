#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> vec(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &vec[i]);
    }
    sort(vec.begin(), vec.end());
    int resp = 0, curVal = vec[0] + 1;
    for(int i = 1; i < n; i++) {
        resp += vec[i] - curVal;
        curVal = vec[i] + 1;
    }
    printf("%d\n", resp);
}