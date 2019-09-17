#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(void) {
	int n;
	cin >> n;
	vector<ll> vec(n+1);
	for(int i = 0; i < n; i++) {
		ll a;
		cin >> a;
		vec[a] = i;
	}
	int m;
	ll v = 0, p = 0;
	cin >> m;
	for(int i = 0; i < m; i++) {
		ll a;
		cin >> a;
		v += vec[a] + 1;
		p += n - vec[a];
	}
	cout << v << " " << p << '\n';
	return 0;
}
