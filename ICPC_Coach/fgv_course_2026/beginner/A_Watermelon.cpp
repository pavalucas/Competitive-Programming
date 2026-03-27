#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
	int kg;
 
	cin >> kg;
 
	if(kg % 2 == 0 && kg != 2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
 
	return 0;
}