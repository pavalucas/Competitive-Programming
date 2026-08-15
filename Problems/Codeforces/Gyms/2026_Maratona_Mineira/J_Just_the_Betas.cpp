#include <bits/stdc++.h>

using namespace std;

#define MAXN 10000009
#define ll long long
bitset<MAXN> bs;
ll sievesize, numDiffPF[MAXN];
vector<ll> primes;
unordered_map<int, int> mapPrimes;

void sieve(ll n) {
    sievesize = n + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i <= sievesize; i++) {
        if(bs[i]) {
            for(ll j = i * i; j <= (ll)sievesize; j += i) bs[j] = 0;
            primes.push_back(i);
        }
    }
}

void primeFactors(ll N) {
    ll PF_idx = 0, PF = primes[PF_idx];
    while(PF * PF <= N) {
        bool is_div = false;
        while(N % PF == 0) {
            N /= PF;
            is_div = true;
        }
        if(is_div) {
            if(mapPrimes.count(PF) > 0)
                mapPrimes[PF]++;
            else
                mapPrimes[PF] = 1;
        }
        PF = primes[++PF_idx];
    }
    if(N != 1) {
        if(mapPrimes.count(N) > 0)
            mapPrimes[N]++;
        else
            mapPrimes[N] = 1;
    }
}

int main()
{
    int n;
    cin >> n;
    sieve(1e6+5);
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        primeFactors((ll)a);
    }
    int result = 2;
    int max_freq = 0;
    for(auto& p : mapPrimes) {
        if(p.second > max_freq) {
            result = p.first;
            max_freq = p.second;
        }
    }
    cout << result << endl;
    
    return 0;
}