#include <bits/stdc++.h>

using namespace std;

int main() {
	int q, n;
	cin >> q;
	while(q--) {
		cin >> n;
		priority_queue<long long, vector<long long>, greater<long long> > pq;
		for(int i = 0; i < n; i++) {
			int a;
			cin >> a;
			pq.push(a);
		}
		bool resp = false;
		while(!pq.empty()) {
			int a = pq.top();
			pq.pop();
			if(a == 2048) {
				resp = true;
				break;
			}
			if(!pq.empty()) {
				int b = pq.top();
				pq.pop();
				if(b == 2048) {
					resp = true;
					break;
				}
				if(a == b) {
					pq.push(a + b);
				}
				else {
					pq.push(b);
				}
			}
		}
		if(resp) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}
