#include <bits/stdc++.h>

#define ll long long

#define TRACE(x...)
#define WATCH(x) TRACE( cout << #x" = " << x << endl)
#define PRINT(x) TRACE(printf(x))
#define WATCHR(a, b) TRACE( for(auto c = a; c != b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end()); } )

using namespace std;

bool checkEqual(int n, const vector<int>& digits, const vector<int>& antDigits) {
    for(int i = 0; i < n; i++) {
        if(digits[i] != antDigits[i]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio( false ); cin.tie(nullptr);
    vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> antDigits = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};
    int n;
    cin >> n;
    vector<string> vec;
    set<char> distinctChar;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for( const char& c : s) {
            distinctChar.insert(c);
        }
        vec.push_back(s);
    }

    vector<ll> contribCharSum(26, 0);
    vector<ll> contribCharResp(26, 0);

    vector<ll> pot10(11);
    pot10[0] = 1;
    for(int i = 1; i < 11; i++) {
        pot10[i] = pot10[i-1] * 10LL;
    }

    for(int i = 0; i < n-1; i++) {
        int tam = (int)vec[i].size();
        for(int j = tam - 1; j >= 0; j--) {
            contribCharSum[vec[i][j] - 'A'] += pot10[tam - 1 - j];
            WATCH(vec[i][j]);
            WATCH(contribCharSum[vec[i][j] - 'A']);
        }
    }

    int tam = (int)vec[n - 1].size();
    for(int j = tam - 1; j >= 0; j--) {
        contribCharResp[vec[n-1][j] - 'A'] += pot10[tam - 1 - j];
        WATCH(vec[n-1][j]);
        WATCH(contribCharResp[vec[n-1][j] - 'A']);
        WATCH(pot10[tam - 1 - j]);
    }


    int resp = 0;
    do {
        array<ll, 26> mapChar;

        int k = 0;
        for(char c : distinctChar) {
            mapChar[c - 'A'] = digits[k++];
        }

        if(checkEqual((int)distinctChar.size(), digits, antDigits)) {
            continue;
        }

        bool firstDigit = false;
        for(int i = 0; i < n; i++) {
            if(mapChar[vec[i][0] - 'A'] == 0) firstDigit = true;
        }
        if(firstDigit) continue;

        ll sum = 0ll, res = 0ll;
        for(const char& c : distinctChar) {
            sum += contribCharSum[c - 'A'] * mapChar[c - 'A'];
            res += contribCharResp[c - 'A'] * mapChar[c - 'A'];
        }
        if(sum == res) resp++;

        antDigits = digits;

    } while(next_permutation(digits.begin(), digits.end()));

    cout << resp << '\n';
    return 0;
}