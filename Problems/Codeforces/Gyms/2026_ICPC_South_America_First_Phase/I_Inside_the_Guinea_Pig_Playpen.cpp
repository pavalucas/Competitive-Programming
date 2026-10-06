#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 1e5 + 10;
vector<ll> guests(MAXN), arrival(MAXN), departure(MAXN);
vector<vector<int>> dependents(MAXN);
stack<int> attending;
map<int, int> indexMap;
vector<pair<ll, ll>> events;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int f, n;
    cin >> f >> n;
    
    for (int i = 0; i < n; ++i) {
        int id;
        cin >> id >> guests[i];
        indexMap[id] = i;
    }  
    
    for (int i = 0; i < n; ++i) {
        char response;
        cin >> response;
        if (response == 'A') {
            ll duration;
            cin >> arrival[i] >> duration;
            departure[i] = arrival[i] + duration;
            attending.push(i);
        } else if (response == 'T') {
            int friendId;
            cin >> friendId;
            if (indexMap.count(friendId) > 0) {
                dependents[indexMap[friendId]].push_back(i);
            }
        }
    }

    
    while (!attending.empty()) {
        int u = attending.top();
        attending.pop();

        events.emplace_back(arrival[u], guests[u]);
        events.emplace_back(departure[u], -guests[u]);

        for (int v : dependents[u]) {
            arrival[v] = arrival[u];
            departure[v] = departure[u];
            attending.push(v);
        }
    }

    sort(events.begin(), events.end());

    ll current = 0, answer = 0;
    for (int i = 0; i < events.size();) {
        ll time = events[i].first;
        while (i < events.size() && events[i].first == time) {
            current += events[i].second;
            ++i;
        }
        answer = max(answer, current);
    }

    cout << answer << endl;
}
