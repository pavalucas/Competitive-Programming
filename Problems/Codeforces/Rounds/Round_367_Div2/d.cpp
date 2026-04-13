#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rp(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep(i, x, n) for (int i = (x); i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)

#define TRACE(x...)
#define WATCH(x) TRACE( cout << #x" = " << x << endl)
#define PRINT(x) TRACE(printf(x))
#define WATCHR(a, b) TRACE( for(auto c = a; c != b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end()); } )

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;

struct Node
{
    int freq;
    Node* child[2];
    Node() : freq(0), child{nullptr, nullptr} {}
    Node(int freq, Node* child0, Node* child1) : freq(freq), child{child0, child1} {}
};

vi getBits(int num) {
    vi result(32, 0);
    unsigned int mask = 1 << 31;
    int i = 0;
    while(mask > 0) {
        result[i] = !!(num & mask);
        mask >>= 1;
        i++;
    }
    return result;
}

void addTrie(Node* node, vi& bits, int i) {
    node->freq++;
    if(i == 32) return;
    if(node->child[bits[i]] == nullptr) {
        Node* newNode = new Node();
        node->child[bits[i]] = newNode;
    }
    addTrie(node->child[bits[i]], bits, i+1);
    return;
}

void removeTrie(Node* node, vi& bits, int i) {
    node->freq--;
    if(i == 32) return;
    if(node->child[bits[i]] == nullptr) {
        cout << "ERROR" << endl;
    }
    removeTrie(node->child[bits[i]], bits, i+1);
    return;
}

void getMaxXOR(Node* node, vi& bits, int i, int& ans) {
    if(i == 32)
        return;
    if(bits[i]) {
        if(node->child[0] != nullptr && node->child[0]->freq > 0) {
            ans |= (bits[i] ^ 0) << (31 - i);
            getMaxXOR(node->child[0], bits, i+1, ans);
        } else {
            getMaxXOR(node->child[1], bits, i+1, ans);
        }
    } else {
        if(node->child[1] != nullptr && node->child[1]->freq > 0) {
            ans |=  (bits[i] ^ 1) << (31 - i);
            getMaxXOR(node->child[1], bits, i+1, ans);
        } else {
            getMaxXOR(node->child[0], bits, i+1, ans);
        }
    }
    WATCH(ans);
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    Node* root = new Node();
    vi bits = getBits(0);
    addTrie(root, bits, 0);
    rp(i,n) {
        char c;
        int a;
        cin >> c >> a;
        bits = getBits(a);
        if(c == '+') {
            addTrie(root, bits, 0);
        } else if(c == '-') {
            removeTrie(root, bits, 0);
        } else {
            int ans = 0;
            getMaxXOR(root, bits, 0, ans);
            cout << ans << endl;
        }
    }
    return 0;
}