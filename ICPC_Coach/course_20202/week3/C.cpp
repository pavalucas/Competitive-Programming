#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    set<int> allVoters;
    set<int> resp;
    int numVot[3];
    cin >> numVot[0] >> numVot[1] >> numVot[2];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < numVot[i]; j++) {
            int a;
            cin >> a;
            if(allVoters.find(a) != allVoters.end()) resp.insert(a);
            else allVoters.insert(a);
        }
    }
    cout << resp.size() << endl;
    for(auto& p : resp) cout << p << endl;
    return 0;
}