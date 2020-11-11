#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, s;
    cin >> n >> s;
    vector<int> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
      long long resp = 0;
    int pos = n/2;
    if(vec[pos] > s)
    {
        for(int i = pos; i >= 0; i--)
        {
            if(vec[i] > s) resp += vec[i] - s;
        }
    }
    else if(vec[pos] < s)
    {
        for(int i = pos; i < n; i++)
        {
            if(vec[i] < s) resp += s - vec[i];
        }
    }
    cout << resp << endl;
    return 0;
}