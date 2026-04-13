#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<char> > mat(110, vector<char>(110, '#'));
vector<vector<int> > visited(110, vector<int>(110, 0));

#define TRACE(x...)
#define WATCH(x) TRACE( cout << #x" = " << x << endl)
#define PRINT(x) TRACE(printf(x))
#define WATCHR(a, b) TRACE( for(auto c = a; c != b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end()); } )

bool isValid(int i, int j) {
	return (i < n && i >= 0 && j < n && j >= 0);
}

pair<int, int> dir[]= {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};

void paintPosition(int i, int j) {
	if(mat[i][j] == '#' || visited[i][j] == 1) return;
	visited[i][j] = 1;
	for(int k = 0; k < 8; k++) {
		int newI = i + dir[k].first;
		int newJ = j + dir[k].second;
		if(isValid(newI, newJ) && visited[newI][newJ] == 0) {
			WATCH(newI);
			WATCH(newJ);
			if(mat[i][j] == 'W') mat[newI][newJ] = 'B';
			else mat[newI][newJ] = 'W';
			paintPosition(newI, newJ);
		}
	}
	return;
}

int main() {	
	cin >> n;
	mat[0][0] = 'W';
	paintPosition(0, 0);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(mat[i][j] == '#') cout << 'B';
			else cout << mat[i][j];
		}
		cout << '\n';
	} 
	return 0;
}
