#include <bits/stdc++.h>

using namespace std;

int n, w, h, l;
vector<vector<char> > mat(11, vector<char>(11));
vector<pair<int, int> > dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
map<vector<pair<int, int> >, int > mapVec;
vector<pair<int, int> > robots(4);

bool isValid(const pair<int, int>& pos, const vector<pair<int, int> > robots) {
    bool ok = (pos.first >= 0 && pos.second >= 0 && pos.first < h && pos.second < w);
    if(!ok) return false;
    if(mat[pos.first][pos.second] == 'W') return false;
    for(int i = 0; i < n; i++) {
        if(robots[i] == pos) return false;
    }
    return true;
}

int bfs() {
    queue<pair<int, vector<pair<int, int> > > > q;
    q.push({0, robots});
    mapVec[robots] = 0;
    while(!q.empty()) {
        auto ele = q.front();
        q.pop();
        int dist = ele.first;
        vector<pair<int, int> > curRobots = ele.second;
        if(dist > l) continue;
        if(mat[curRobots[0].first][curRobots[0].second] == 'X') return dist;
        for(int rob = 0; rob < n; rob++) {
            vector<pair<int, int> > modRobots;
            for(int i = 0; i < 4; i++) {
                modRobots.assign(curRobots.begin(), curRobots.end());
                pair<int, int> newPos = {modRobots[rob].first + dir[i].first,
                                         modRobots[rob].second + dir[i].second};
                while(isValid(newPos, modRobots)) {
                    modRobots[rob].first += dir[i].first;
                    modRobots[rob].second += dir[i].second;
                    newPos = {modRobots[rob].first + dir[i].first,
                              modRobots[rob].second + dir[i].second};
                }
                if(mapVec.find(modRobots) == mapVec.end()) {
                    mapVec[modRobots] = dist + 1;
                    q.push({dist + 1, modRobots});
                }
            }
        }
    }
    return -1;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> w >> h >> l;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> mat[i][j];
            if(mat[i][j] != 'W' && mat[i][j] != '.' && mat[i][j] != 'X') {
                robots[mat[i][j] - '1'] = {i, j};
            }
        }
    }
    int resp = bfs();
    if(resp == -1) cout << "NO SOLUTION" << '\n';
    else cout << resp << '\n';
    return 0;
}