#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    vector<int> vec(3);
    int sum = 0;
    for(int j = 0; j < 3; ++j) {
      cin >> vec[j];
      sum += vec[j];
    }
    int maxEle = *max_element(vec.begin(), vec.end());
    int minEle = *min_element(vec.begin(), vec.end());
    cout << "Case " << i + 1 << ": " << sum - maxEle - minEle << endl;
  }
}