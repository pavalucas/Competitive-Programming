#include <unordered_map>
#include <iostream>

using namespace std;

int main(void)
{
	unordered_map<string, int> hashTab;
	int entries;

	cin >> entries;

	for(int i = 0; i < entries; i++)
	{
		string s;
		cin >> s;

		if(hashTab.find(s) == hashTab.end())
		{
			hashTab[s] = 0;
			cout << "OK" << endl;
		}
		else
		{
			hashTab[s] = hashTab[s] + 1;

			cout << s << hashTab[s] << endl;
		}
	}


	return 0;
}