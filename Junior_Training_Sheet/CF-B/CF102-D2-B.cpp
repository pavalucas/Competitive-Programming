#include <bits/stdc++.h>

using namespace std;

int main(void) {
	string s;
	cin >> s;
	int resp = 0;
	while(s.size() > 1) {
		string newS = "";
		int sum = 0;
		for(char c : s) {
			sum += c - '0';
		}
		while(sum > 0) {
			newS += '0' + (sum % 10);
			sum /= 10;
		}
		reverse(newS.begin(), newS.end());
		s = newS;
		resp++;
	}
	cout << resp << endl;
	return 0;
}
