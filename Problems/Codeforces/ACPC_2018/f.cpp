#include <bits/stdc++.h>

using namespace std;

#define TRACE(x...)
#define WATCH(x) TRACE( cout << #x" = " << x << endl)
#define PRINT(x) TRACE(printf(x))
#define WATCHR(a, b) TRACE( for(auto c = a; c != b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end()); } )

int mat[310][310];
double prob[310][310];
double dp[310][2];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    ifstream in("fetiera.in");
    in >> t;
    while(t--) {
        int n, k;
        in >> n >> k;
        int qntMat = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                in >> mat[i][j];
                qntMat += (n - i) * (n - j);
            }
        }

        WATCH(qntMat);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                prob[i][j] = ((i + 1) * (j + 1) * (n - i) * (n - j)) / ((double) qntMat);
                WATCH(prob[i][j]);
            }
        }

        double resp = 0.0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dp[0][mat[i][j]] = 1;
                dp[0][1 - mat[i][j]] = 0;
                for(int h = 1; h <= k; h++) {
                    for(int s = 0; s < 2; s++) {
                        dp[h][s] = dp[h - 1][s] * (1 - prob[i][j]) + dp[h - 1][1 - s] * prob[i][j];
                    }
                }
                resp += dp[k][1];
            }
        }
        cout << fixed << setprecision(8);
        cout << resp << '\n';

    }
    return 0;
}