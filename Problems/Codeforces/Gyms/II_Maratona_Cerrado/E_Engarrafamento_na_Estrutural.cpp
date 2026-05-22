#include <bits/stdc++.h>
using namespace std;

// TODO: Fill with the maximum value needed by the problem constraints.
const int MAXN = 1e7 + 10;

// TODO: Fill/add the input variables needed by the problem.
int n;

vector<int> primes;
bitset<MAXN> bs;
int f[MAXN], pw[MAXN], spf[MAXN];

int g(int p, int k) {
    if (p == 1) return 1;

    return (k == 0) - (k == 1);

    // int q = 1;
    // for (int i = 1; i < k; i++) q *= p;
    // return q * (p - 1);
}

void sieve(int n) {
    bs.set();
    bs[0] = bs[1] = 0;
    primes.clear();
    f[1] = g(1, 1);
    spf[1] = 1;


    for (int i = 2; i <= n; i++) {
        if (bs[i]) {
            primes.push_back(i);
            f[i] = g(i, 1);
            pw[i] = 1;
            spf[i] = i;
        }

        for (int j = 0; j < (int)primes.size() && 1LL * i * primes[j] <= n; j++) {
            int p = primes[j];
            int x = i * primes[j];
            bs[x] = 0;
            spf[x] = p;

            if (i % primes[j] == 0) {
                int pwr = 1;
                for (int k = 0; k < pw[i]; k++) pwr *= primes[j];

                f[x] = f[i / pwr] * g(primes[j], pw[i] + 1);
                pw[x] = pw[i] + 1;
                break;
            }

            f[x] = f[i] * f[primes[j]];
            pw[x] = 1;
        }
    }
}

vector<pair<int, int>> factorize(int x) {
    vector<pair<int, int>> factors;

    while (x > 1) {
        int p = spf[x];
        int cnt = 0;

        while (x % p == 0) {
            x /= p;
            cnt++;
        }

        factors.push_back({p, cnt});
    }

    return factors;
}

void solve() {
    cin >> n;
    sieve(MAXN);
    vector<pair<int, int>> factors = factorize(n);
    for (auto p : factors) {
        cout << p.first << ": " << p.second << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
