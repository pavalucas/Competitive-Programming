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

vector<ull> vec(101);
map<ull, vector<ull>> gra;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    vector<ull> resp(n);

    // smallest number not divisible by 3
    ull minND = numeric_limits<ull>::max();

    int qntND = 0, qntDE = 0, qntDO = 0;
    rp(i,n) {
        cin >> vec[i];
        if(vec[i] % 3) {
            minND = min(minND, vec[i]);
            qntND++;
        }
        else {
            vector<ull> tmp{vec[i]*3};
            if(vec[i] % 2 == 0) {
                tmp.pb(vec[i]/2);
            }
            gra[vec[i]] = tmp;
        }
    }
    
    if(qntND > 0) {
        ull tmp = minND;
        for(int i = n-qntND; i < n; i++) {
            resp[i] = tmp;
            tmp *= 2;
        }
        tmp = minND * 3;
        for(int i = n-qntND-1; i >= 0; i--) {
            resp[i] = tmp;
            vector<ull> v = gra[tmp];
            for(ull at : v) {
                if(gra.find(at) != gra.end()) {
                    tmp = at;
               }
            }
        }
    } else {
        ull lastNum;
        // check which number is the last one
        for(ull num : vec) {
            if(gra.find(num*2) == gra.end() && gra.find(num/3) == gra.end()) {
                lastNum = num;
                break;
            }
        }
        ull tmp = lastNum;
        for(int i = n-1; i >= 0; i--) {
            resp[i] = tmp;
            vector<ull> v = gra[tmp];
            for(ull at : v) {
                if(gra.find(at) != gra.end()) {
                    tmp = at;
               }
            }
        } 
    }

    rp(i, n) {
        cout << resp[i] << " ";
    }
    cout << endl;

    return 0;
}
