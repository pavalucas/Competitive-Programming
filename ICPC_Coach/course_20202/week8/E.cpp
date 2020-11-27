#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  while(n != 0) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++) {
      int a;
      cin >> a;
      pq.emplace(a);
    }
    int result = 0;
    while(!pq.empty()) {
      int a = pq.top();
      pq.pop();
      int b = pq.top();
      pq.pop();
      result += a + b;
      if(!pq.empty()) {
        pq.emplace(a+b);
      }
    }
    cout << result << '\n';
    cin >> n;
  }
}