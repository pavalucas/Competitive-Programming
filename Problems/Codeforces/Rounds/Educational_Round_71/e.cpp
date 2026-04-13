#include <bits/stdc++.h>
 
using namespace std;
 
#define TRACE(x...)
#define WATCH(x) TRACE( cout << #x" = " << x << endl)
#define PRINT(x) TRACE(printf(x))
#define WATCHR(a, b) TRACE( for(auto c = a; c != b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end()); } )

int main(void) {
	cout << "? ";
	for(int i = 1; i <= 100; i++) {
		cout << i << " ";
	}
	cout << '\n';
	cout.flush();
	int res1;
	cin >> res1;
	
	cout << "? ";
	for(int i = 1; i <= 100; i++) {
		cout << (i << 7) << " ";
	}
	cout << '\n';
	cout.flush();
	int res2;
	cin >> res2;
	
	int x = 0;
	x |= (res1 & (((1 << 7) - 1) << 7));
	x |= (res2 & ((1 << 7) - 1));
	cout << "! " << x << '\n'; 
	
	return 0;
}
