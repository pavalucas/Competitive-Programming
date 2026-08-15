#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    deque<pair<int, int>> dq;
    map<int, int, greater<int>> mp;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if(mp.find(a) == mp.end()) {
            mp[a] = i;
            dq.push_back(make_pair(a, i));
        } else {
            bool cont = true;
            while(cont) {
                pair<int, int> last = dq.front();
                dq.pop_front();
                int cur_elem = last.first;
                mp.erase(cur_elem);
                if(cur_elem == a) {
                    cont = false;
                } 
            }
            mp[a] = i;
            dq.push_back(make_pair(a, i));
        }
        auto it = *mp.begin();
        cout << it.first << " " << it.second + 1 << endl;
    }

    return 0;
}