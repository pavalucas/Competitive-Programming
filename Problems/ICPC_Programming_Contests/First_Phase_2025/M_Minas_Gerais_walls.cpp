#include <bits/stdc++.h>
using namespace std;
vector<int> pref(1e5 + 10);
vector<int> suf(1e5 + 10);
vector<int> v(1e5 + 10);
vector<int> v2(1e5 + 10);
int main()
{
    int n, k;
    cin >> n >> k;
    
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v[i] = tmp;
        v2[i] = tmp + i;
    }
    
    pref[0] = v[0];
    for(int i = 1; i < n; i++) {
        pref[i] = min(v[i], pref[i-1]);
    }
    
    suf[n-1] = v[n-1];
    for(int i = n-2; i >= 0; i--) {
        suf[i] = min(v[i], suf[i+1]);
    }
    
    
    multiset<int> ms;
    int sol = 1;
    for(int i = 0; i < n; i++) {
        if(i - k >= 0) {
            ms.erase(ms.find(v2[i - k]));
        }
        ms.insert(v2[i]);
        
        int resp = *ms.begin() - i + k;
        if(i - k >= 0) {
            resp = min(resp, pref[i-k]);
        }
        if(i + 1 < n) {
            resp = min(resp, suf[i+1]);
        }
        sol = max(sol, resp);
        
    }
    cout << sol << endl;

    return 0;
}