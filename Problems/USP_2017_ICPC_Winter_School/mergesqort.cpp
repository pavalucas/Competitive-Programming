/* Link: https://people.ksp.sk/~acm/brazil17/problem.php?contest=Camp%20day%201&problem=mergesqort */

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull ast = 0;

void sqrtMergesort(int n)
{
    if(n == 1)
        return;
    else
    {
        ast += n;
        int n_left = floor(sqrt(n));
        int n_right = n - n_left;
        sqrtMergesort(n_left);
        sqrtMergesort(n_right);
        return;
    }
}

int main(void)
{
    int n;
    cin >> n;

    sqrtMergesort(n);
    cout << ast << endl;
}