#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> vec(n+1);
	vec[0] = 0;
	for(int i = 1; i <= n; i++) cin >> vec[i];
	int resp = 0, need = 0;
	for(int i = 0; i < n; i++) {
		int curNeed = vec[i] - vec[i+1];
		if(curNeed < 0) need += curNeed;
		else {
			if(need < 0) {
				resp += abs(need);
				need = 0;
			}
			need += curNeed;
		} 
	}
	if(need < 0) resp += abs(need);
	cout << resp << endl;
}
