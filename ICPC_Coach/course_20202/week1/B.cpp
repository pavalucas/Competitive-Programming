#include <bits/stdc++.h>

using namespace std;

bool checkValid(int x1, int y1, int x2, int y2) {
  if(x1 == x2 || y1 == y2) return true;
  if(x1 + y1 == x2 + y2) return true;
  return x1 - y1 == x2 - y2;
}

int main() {
  vector<string> board;
  vector<pair<int, int>> queenPos;
  for(int i = 0; i < 8; i++) {
    string s;
    cin >> s;
    board.emplace_back(s);
    for(int j = 0; j < 8; j++) {
      if(s[j] == '*') queenPos.emplace_back(make_pair(i, j));
    }
  }
  if((int)queenPos.size() != 8) {
    cout << "invalid" << '\n';
    return 0;
  }
  for(int i = 0; i < (int) queenPos.size(); i++) {
    for(int j = 0; j < (int) queenPos.size(); j++) {
      if(i != j && checkValid(queenPos[i].first, queenPos[i].second, queenPos[j].first, queenPos[j].second)) {
        cout << "invalid" << '\n';
        return 0;
      }
    }
  }
  cout << "valid" << '\n';
  return 0;
}