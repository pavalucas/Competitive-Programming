#include <bits/stdc++.h>
using namespace std;

#define TRACE(x...)
#define WATCH(x) TRACE( cout << #x" = " << x << endl)
#define PRINT(x) TRACE(printf(x))
#define WATCHR(a, b) TRACE( for(auto c = a; c != b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end()); } )
#define sz(x) ((int) x.size())

vector<int> z_function(string s) {
	int n = (int) s.length();
	vector<int> z(n);
	for(int i = 1, l = 0, r = 0; i < n; ++i) {
		if(i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if(i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	return z;
}

int main(void) {
	string s;
	cin >> s;
	int n = (int) s.size();
	vector<int> z = z_function(s);
	vector<int> candidates, zCand;
	WATCHC(z);
	for(int i = n-1; i >= 0; i--) {
		if(i + z[i] == n) {
			candidates.push_back(i);
			zCand.push_back(z[i]);
		}
	}
	WATCHC(zCand);
	int respVal = 0, maxMiddle = 0;
	if(zCand.size() > 0) {
		for(int i = 0; i < n; i++) {
			if(z[i] > 0 && i + z[i] < n) {
				maxMiddle = max(maxMiddle, z[i]);
			}
		}
	}
	for(int i = sz(zCand) - 1; i >= 0; i--) {
		if(maxMiddle >= zCand[i]) {
			respVal = zCand[i];
			break;
		}
	}
	
	if(sz(zCand) > 1) respVal = max(respVal, zCand[sz(zCand) - 2]);
	
	if(respVal != 0) {
		for(int i = 0; i < respVal; i++) {
			cout << s[i];
		}
	} else {
		cout << "Just a legend";	
	}
	
	cout << '\n';
	
	return 0;
}
