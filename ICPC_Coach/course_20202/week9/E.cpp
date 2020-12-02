#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  set<string> words;
  int poland = 0, enemy = 0, both = 0;
  for(int i = 0; i < n; i++) {
    string a;
    cin >> a;
    words.emplace(a);
    poland++;
  }
  for(int i = 0; i < m; i++) {
    string a;
    cin >> a;
    if(words.count(a)) {
      both++;
    } else {
      words.emplace(a);
    }
    enemy++;
  }
  bool resultIsPoland = true;
  bool ok = true, isPoland = true;
  while(ok) {
    if(isPoland) {
      if(poland <= 0) {
        resultIsPoland = false;
        ok = false;
      } else {
        if(both > 0) {
          both--;
          enemy--;
        }
        poland--;
      }
    } else {
      if(enemy <= 0) {
        resultIsPoland = true;
        ok = false;
      } else {
        if(both > 0) {
          both--;
          poland--;
        }
        enemy--;
      }
    }
    isPoland = !isPoland;
  }
  if(resultIsPoland) cout << "YES\n";
  else cout << "NO\n";

}