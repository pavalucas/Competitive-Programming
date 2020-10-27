#include <bits/stdc++.h>

using namespace std;

struct union_find {
  vector<int> parent;
  vector<int> friendSize;
  union_find() {

  }

  void addToUF() {
    parent.emplace_back(parent.size());
    friendSize.emplace_back(1);
  }

  int find(int x) {
    if(parent[x] == x) return x;
    else {
      parent[x] = find(parent[x]);
      return parent[x];
    }
  }

  void unite(int x, int y) {
    int parentX = find(x);
    int parentY = find(y);
    if(parentX == parentY) return;
    parent[parentX] = parentY;
    friendSize[parentY] += friendSize[parentX];
  }

  int getSize(int x) {
    return friendSize[find(x)];
  }

};

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);
  int test;
  cin >> test;
  while(test--) {
    int n;
    cin >> n;
    map<string, int> strMap;
    union_find uf = union_find();
    for(int i = 0; i < n; i++) {
      string str1, str2;
      int index1, index2;
      cin >> str1 >> str2;
      if(strMap.count(str1)) {
        index1 = strMap[str1];
      } else {
        index1 = strMap.size();
        strMap[str1] = index1;
        uf.addToUF();
      }

      if(strMap.count(str2)) {
        index2 = strMap[str2];
      } else {
        index2 = strMap.size();
        strMap[str2] = index2;
        uf.addToUF();
      }

      uf.unite(index1, index2);
      cout << uf.getSize(index1) << '\n';
    }
  }
}