#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> freqA(27);
vector<ll> freqP(27);

void addFreq(string& s, vector<ll>& freq, int k) {
    for(char& c : s) {
        freq[c - 'a'] += (ll) k;
    }
}

bool checkEqual() {
    for(int i = 0; i < freqA.size(); i++) {
        if(freqA[i] != freqP[i]) return false;
    }
    return true;
}

int checkDiffPrefix() {
    for(int i = 0; i < freqA.size(); i++) {
        if(freqA[i] < freqP[i]) {
            for(int j = i + 1; j < freqA.size(); j++) {
                if(freqA[j] != 0) return 0;
            }
            return 1;
        }
        if(freqA[i] > freqP[i]) {
            for(int j = i + 1; j < freqA.size(); j++) {
                if(freqP[j] != 0) return 0;
            }
            return -1;
        }
    }
    return 0;
}

int compareFreq() {
    for(int i = 0; i < freqA.size(); i++) {
        if(freqA[i] < freqP[i]) return -1;
        if(freqA[i] > freqP[i]) return 1;
    }
    return 0;
}

void outputCout(int result) {
    if(result > 0) {
        cout << "ADA" << endl;
    } else if(result < 0) {
        cout << "PY" << endl;
    }
}

int main() {
    string sa, sp;
    cin >> sa >> sp;
    addFreq(sa, freqA, 1);
    addFreq(sp, freqP, 1);
    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        int k;
        string s;
        if(t == 1) {
            cin >> k >> s;
            addFreq(s, freqA, k);
        } else if(t == 2) {
            cin >> k >> s;
            addFreq(s, freqP, k);
        } else {
            bool isEqual = checkEqual();
            if(isEqual)
                cout << "EMPATE" << endl;
            else {
                int isPrefix = checkDiffPrefix();
                outputCout(isPrefix);
                if(isPrefix == 0) {
                    int result = compareFreq();
                    outputCout(result);
                }
            }
        }
    }
    return 0;
}
