#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ifstream in("coffee.in");
    int t;
    in >> t;
    map<string, int> mapSize;
    mapSize["small"] = 0;
    mapSize["medium"] = 1;
    mapSize["large"] = 2;
    while(t--) {
        map<string, vector<int> > mapCof;
        map<string, int > mapPerson;
        int c, p;
        in >> c >> p;
        vector<string> vecPerson(p);
        int fee = 100 / p;
        for(int i = 0; i < c; i++) {
            string s;
            in >> s;
            vector<int> vecSize(3);
            in >> vecSize[0] >> vecSize[1] >> vecSize[2];
            mapCof[s] = vecSize;
        }

        for(int i = 0; i < p; i++) {
            in >> vecPerson[i];
            string s1, s2;
            in >> s1 >> s2;
            mapPerson[vecPerson[i]] = mapCof[s2][mapSize[s1]] + fee;
        }

        for(string s : vecPerson) {
            int val = mapPerson[s];
            if(val % 5 == 1) val--;
            else if(val % 5 == 4) val++;
            cout << s << " " << val << '\n';
        }

    }
    return 0;
}