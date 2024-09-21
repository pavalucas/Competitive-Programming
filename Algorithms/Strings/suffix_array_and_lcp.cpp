#include <bits/stdc++.h>
using namespace std;

// from https://github.com/splucs/Competitive-Programming?tab=readme-ov-file

const int MAXN = 1e5 + 10;
int tsa [MAXN], c[MAXN], tc[MAXN], head[MAXN];

void bucket(int sa[], int n, int L) {
    memset(&head, 0, sizeof(head));
    for (int i = 0; i < n; i++) head[c[i]]++;
    int maxi = max(300, n), k = 0;
    for (int i = 0; i < maxi; i++)
        swap(k, head[i]), k += head[i];
    for(int i = 0; i < n; i++) {
        int j = (sa[i] - L + n) % n;
        tsa[head[c[j]]++] = j;
    }
    memcpy(sa, tsa, n * sizeof(int));
}

void suffixArray(string str, int sa[]) {
    int n = str.size() + 1;
    cout << n << endl;
    for (int i = 0; i < n; i++) 
        sa[i] = i, c[i] = str[i];
    bucket(sa, n, 0);
    for(int L = 1; L < n; L <<= 1) {
        bucket(sa, n, L);
        for(int i = 0, cc = -1; i < n; i++)
            tc[sa[i]] = (i == 0 || c[sa[i]] != c[sa[i-1]] || c[(sa[i] + L) % n] != c[(sa[i-1] + L) % n]) ? ++cc : cc;
        memcpy(c, tc, n * sizeof(int));
    }
    for(int i = 0; i < n - 1; i++) sa[i] = sa[i + 1];
}

int inv [MAXN] ;
int computeLcp(string str, int sa[], int lcp[]) {
    int n = str.size(), k = 0;
    for(int i = 0; i < n; i++) inv[sa[i]] = i;
    for(int j = 0; j < n; j++) {
        int i = inv[j];
        if(k < 0) k = 0;
        while (i > 0 && str[sa[i] + k] == str[sa[i-1] + k])
            k++;
        lcp[i] = k--;
    }
}

int main() {
    string str;
    cin >> str;
    int sa[MAXN], lcp[MAXN];
    suffixArray(str, sa);
    computeLcp(str, sa, lcp);
    cout << "Suffix Array: ";
    for (int i = 0; i < str.size(); i++) cout << sa[i] << " ";
    cout << endl;
    cout << "LCP Array: ";
    for (int i = 0; i < str.size(); i++) cout << lcp[i] << " ";
    cout << endl;
    return 0;
    /*
    Input: 1213121
    Output:
    8
    Suffix Array: 7 6 4 0 2 5 1 3 
    LCP Array: 0 0 1 3 1 0 2 0 
    */
}