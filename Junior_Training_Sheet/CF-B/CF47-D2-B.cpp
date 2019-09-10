#include <bits/stdc++.h>

using namespace std;

int main(void) {
	string s[3];
	vector<pair<int, char> > count;
	map<string, int> mapVal;
	for(int i = 0; i < 3; i++) {
		cin >> s[i];
		count.push_back({0, 'A' + i});
	}
	for(int i = 0; i < 3; i++) {
		char a = s[i][0], b = s[i][1], c = s[i][2];
		if(b == '>') {
			count[a - 'A'].first++;
		} else {
			count[c - 'A'].first++;
		}
	}

	sort(count.begin(), count.end());

	if(count[0].first == 1 && count[2].first == 1) cout << "Impossible" << endl;
	else {
		for(auto p : count) {
			cout << p.second;
		}
		cout << endl;
	}

	return 0;
}