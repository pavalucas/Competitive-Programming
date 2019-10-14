#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	string s = "ROYGBIV";
	int extra = n - 7;
	string toAdd = "GBIV";
	for(int i = 0; i < extra / 4; i++) s += toAdd;
	for(int i = 0; i < extra % 4; i++) s += toAdd[i];
	cout << s << '\n';
	return 0;
}
