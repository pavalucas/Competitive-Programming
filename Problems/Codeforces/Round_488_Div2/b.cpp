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

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;

typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;



int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<tuple<ll,ll,ll>> kni(n);
    rp(i, n) {
        ll a;
        cin >> a;
        get<0>(kni[i]) = a;
    }

    rp(i, n) {
        ll a;
        cin >> a;
        get<1>(kni[i]) = a;
        get<2>(kni[i]) = i;
    }
    sort(all(kni));
    vi resp(n);
    priority_queue<ll, vector<ll>, greater<ll>> coin;
    ll sum = 0;
    rp(i,n) {
        if(i == 0) {
            resp[get<2>(kni[i])] = get<1>(kni[i]);
            if(coin.size() < k) {
                sum += get<1>(kni[i]);
                coin.push(get<1>(kni[i]));
            }
        }
        else {
            resp[get<2>(kni[i])] = sum + get<1>(kni[i]);
            if(coin.size() < k) {
                sum += get<1>(kni[i]);
                coin.push(get<1>(kni[i]));
            } else {
                if(!coin.empty()) {
                    ll low = coin.top();
                    if(get<1>(kni[i]) > low) {
                        coin.pop();
                        coin.push(get<1>(kni[i]));
                        sum -= low;
                        sum += get<1>(kni[i]);
                    }
                }
            }
        }
    }

    rp(i,n) {
        cout << resp[i] << " ";
    }
    cout << endl;
    return 0;
}