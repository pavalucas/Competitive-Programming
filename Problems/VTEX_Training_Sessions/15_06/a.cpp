#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int k;
	string s1, s2;
	cin >> k >> s1 >> s2;
	int n = (int) s1.size();
	int equalPos = 0;
	for(int i = 0; i < n; i++) {
		if(s1[i] == s2[i]) equalPos++;
	}
	int notEqual = n - equalPos;
	cout << min(k, equalPos) + min(n - k, notEqual) << endl;
	return 0;
}