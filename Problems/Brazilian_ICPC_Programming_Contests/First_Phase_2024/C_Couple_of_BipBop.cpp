#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;
int tsa [MAXN], c[MAXN], tc[MAXN], head[MAXN];
int str[MAXN];
int sa[MAXN], lcp[MAXN];

void bucket(int n, int L) {
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

void suffixArray(int _n) {
    int n = _n + 1;
    for (int i = 0; i < n; i++) 
        sa[i] = i, c[i] = str[i];
    bucket(n, 0);
    for(int L = 1; L < n; L <<= 1) {
        bucket(n, L);
        for(int i = 0, cc = -1; i < n; i++)
            tc[sa[i]] = (i == 0 || c[sa[i]] != c[sa[i-1]] || c[(sa[i] + L) % n] != c[(sa[i-1] + L) % n]) ? ++cc : cc;
        memcpy(c, tc, n * sizeof(int));
    }
    for(int i = 0; i < n - 1; i++) sa[i] = sa[i + 1];
}

int inv [MAXN] ;
int computeLcp(int n) {
    int k = 0;
    for(int i = 0; i < n; i++) inv[sa[i]] = i;
    for(int j = 0; j < n; j++) {
        int i = inv[j];
        if(k < 0) k = 0;
        while (i > 0 && str[sa[i] + k] == str[sa[i-1] + k])
            k++;
        lcp[i] = k--;
    }
}

template <typename T>
struct SegTree{
    int N;
    T dummy;
    vector<T> st;
    T op(const T& a, const T& b){
        return min(a,b);
    }
    SegTree(int _N, T _dummy) : N(_N), dummy(_dummy){
        st.assign(4*_N, dummy);
    }
    void update(int node, int start, int end, int idx, T val) {

        if(start > idx || end < idx) return;
        if(start == end && start == idx){ st[node] = val; return;}

        update(2*node, start, (start+end)/2, idx, val);
        update(2*node+1, (start+end)/2+1, end, idx, val);

        st[node] = op(st[2*node], st[2*node+1]);

    }
    T query(int node, int start, int end, int l, int r){
        if(start > r || end < l) return dummy;
        if(start >= l && end <= r) return st[node];
        return op(query(2*node, start, (start+end)/2, l, r), query(2*node+1, (start+end)/2 + 1, end, l, r));
    }
};

int card(int a, int b) { return b - a + 1; }

ll solve(int l, int r, SegTree<pair<int, int>>& st, int n) {
    if(l > r) return 0;
    if(l == r) return n - sa[l];
    // cout << l << " " << r << endl;
    pair<int, int> p = st.query(1, 0, n-1, l + 1, r);
    int idx = p.second;
    // cout << l << " " << r << " " << idx << endl;
    return (ll) lcp[idx] * card(l, idx - 1) * card(idx, r) * 2 + solve(l, idx - 1, st, n) + solve(idx, r, st, n);
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> str[i];
    // str[n++] = -1;
    suffixArray(n);
    // cout << "Suffix Array: ";
    // for(int i = 0; i < n; i++) cout << sa[i] << " ";
    cout << endl;
    computeLcp(n);
    // cout << "LCP: ";
    // for(int i = 0; i < n; i++) cout << lcp[i] << " ";
    cout << endl;
    // n--;
    SegTree<pair<int, int>> st(MAXN, make_pair(INT_MAX, INT_MAX));
    for(int i = 0; i < n; i++) {
        // cout << "idx: " << i << " lcp: " << lcp[i] << endl;
        st.update(1, 0, n-1, i, make_pair(lcp[i], i));
    }
    // cout << st.query(1, 0, n-1, 1, n).second << endl;
    ll num = solve(0, n-1, st, n), den = (ll) n * n;
    ll g = __gcd(num, den);
    cout << num/g << "/" << den/g << endl;
    return 0;
}