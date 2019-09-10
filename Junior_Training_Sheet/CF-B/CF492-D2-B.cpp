#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, l;
	cin >> n >> l;
	vector<int> vec;
	double resp = 0.0;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	sort(vec.begin(), vec.end());
	resp = (double) max(vec[0], l - vec[n-1]);
	for(int i = 0; i < n-1; i++) {
		resp = max(resp, (vec[i + 1] - vec[i]) / 2.0);
	}
	cout << fixed << setprecision(10);
	cout << resp << endl;
}