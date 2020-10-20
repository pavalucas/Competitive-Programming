#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  while(cin >> n) {
    queue<int> q;
    stack<int> st;
    priority_queue<int> pq;
    bool isQ = true, isSt = true, isPq = true;
    for(int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      if(a == 1) {
        q.emplace(b);
        pq.emplace(b);
        st.emplace(b);
      } else {
        if(q.empty()) {
          isQ = false;
          isSt = false;
          isPq = false;
        } else {
          if(q.front() != b) isQ = false;
          if(st.top() != b) isSt = false;
          if(pq.top() != b) isPq = false;
          q.pop();
          st.pop();
          pq.pop();
        }
      }
    }
    if(isQ && !isSt && !isPq) cout << "queue" << '\n';
    else if(!isQ && isSt && !isPq) cout << "stack" << '\n';
    else if(!isQ && !isSt && isPq) cout << "priority queue" << '\n';
    else if(!isQ && !isSt && !isPq) cout << "impossible" << '\n';
    else cout << "not sure" << '\n';
  }
}