#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n;
int m;
int q, k;
vector<string> dict(N);
vector<string> text(N);
map<string, int> id;
int x[N];
int y[N];

string query(vector<string>& vq) {
    int best = 0;
    int vqSize = vq.size() - 1;
    int sumX = 0;
    int sumY = 0;
    for(int i = 0; i < m-1; i++) {
        int len = 0;
        while(i - len >= 0 and len < k and vq[vqSize - len] == text[i - len]) {
            len++;
        }
        if(len > best) {
            best = len;
            int curId = id[text[i+1]];
            sumX = x[curId];
            sumY = y[curId];
        } else if (len == best) {
            int curId = id[text[i+1]];
            sumX += x[curId];
            sumY += y[curId];
        }
    }
    if(best == 0) {
        return "*";
    }

    // computar similaridade
    string bestWord;
    int bestVal = -1e9;
    for(int i = 0; i < n; i++) {
        int curVal = sumX*x[i] + sumY*y[i];
        if(curVal > bestVal) {
            bestVal = curVal;
            bestWord = dict[i];
        }
    }
    return bestWord;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> dict[i] >> x[i] >> y [i];
        id[dict[i]] = i;
    }

    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> text[i];
        if(id.find(text[i]) == id.end()) {
            dict[n] = text[i];
            id[text[i]] = n;
            x[n] = 0;
            y[n] = 0;
            n++;
        }
    }


    cin >> q >> k;

    for(int i = 0; i < q; i++) {
        int qSize;
        cin >> qSize;
        vector<string> vq(qSize);
        for(int j = 0; j < qSize; j++) {
            cin >> vq[j];
            cout << vq[j] << " ";
        }
        string bestWord = query(vq);
        cout << bestWord << endl;

    }

    return 0;
}
