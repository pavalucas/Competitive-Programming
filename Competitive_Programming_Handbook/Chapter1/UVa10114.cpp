#include <bits/stdc++.h>

using namespace std;

int M = 110;
vector<double> rate(M);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    double downPay, loanVal, months;
    cin >> months >> downPay >> loanVal >> n;
    while(months > 0) {
        fill(rate.begin(), rate.end(), 0.0);
        while(n--) {
            int idx;
            double percent;
            cin >> idx >> percent;
            rate[idx] = percent;
        }
        for(int i = 1; i <= M; i++) {
            if(rate[i] == 0) {
                rate[i] = rate[i-1];
            }
        }
        
        double monthPay = loanVal / months;
        double carVal = loanVal + downPay;
        carVal = carVal - carVal * rate[0];
        int res = 0;
        while(loanVal >= carVal) {
            res++;
            loanVal -= monthPay;
            carVal -= carVal * rate[res];
        }
        cout << res << " " << (res != 1? "months" : "month") << "\n";
        cin >> months >> downPay >> loanVal >> n;
    }
    return 0;
}