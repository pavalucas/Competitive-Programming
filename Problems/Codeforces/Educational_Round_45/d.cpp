#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rp(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)

#define TRACE(x...)
#define PRINT(x...)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl )

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int n;
int mat[1001][1001] = {0};

void connect(int i, int j) {
    mat[i][j] = 1;
    mat[j][i] = 1;
}

void inverse() {
    rp(i, n) {
        rp(j, n) {
            if(i != j) {
                if(mat[i][j]) mat[i][j] = 0;
                else mat[i][j] = 1;
            }
        }
    }
}

void printMat() {
    rp(i, n) {
        rp(j, n) {
            cout << mat[i][j];
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a, b;
    cin >> n >> a >> b;
    if((n == 2 && a == 1 && b == 1) ||
        (n == 3 && a == 1 && b == 1) ||
        min(a, b) > 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        rp(i, n - max(a, b)) connect(i, i+1);
        if(b > a) inverse();
        printMat();
    }
    return 0;
}
