#include<bits/stdc++.h>

// define ll as long long
#define ll long long

using namespace std;
int max_num = 1e6;


int main() {
    int t;
    cin >> t;
    vector<ll> arr(max_num+10);
    for(ll i = 0; i < max_num; i++) 
        arr[i] = (i*(i+1))/2;

    while(t--) {
        // sum 1 to n given n
        ll l, r;
        cin >> l >> r;
        ll diff = r - l;
        int idx = lower_bound(arr.begin(), arr.end(), diff) - arr.begin();
        if (arr[idx] > diff) idx--;
        cout << idx + 1 << endl;
    }
    return 0;
}