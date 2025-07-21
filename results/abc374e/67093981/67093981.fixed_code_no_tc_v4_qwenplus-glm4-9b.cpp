#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct{ int a, b, p, q; } p;
const int MOD = 10000;

int main() {
    int N, X;
    scanf("%d %d", &N, &X);

    vector<p> A(N);
    for (int i = 0; i < N; ++i) {
        int a, b, p, q;
        scanf("%d %d %d %d", &a, &p, &b, &q);
        A[i] = {a, b, p, q};
        // Ensure a*q <= b*p by swapping if necessary
        if (a * q > b * p) swap(a, b), swap(p, q);
    }

    long long dp[100][MOD];
    fill_n(dp[0], MOD, 0LL);

    // Initialize dp array
    for (int i = 0; i < N; ++i) {
        long long dpa = A[i].p * A[i].a;
        long long dpb = A[i].q * A[i].b;
        for (int j = 0; j < MOD; ++j) {
            dp[i][j] = min(dp[i - 1][max(j - dpa, 0)] + dpb, dp[i - 1][max(j - dpb, 0)] + dpa);
        }
    }

    long long lo = 1, hi = 1e9;
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        long long cost = 0;
        for (int i = 0; i < N; ++i) {
            cost += dp[i][mid % (A[i].a * A[i].b)];
            if (cost > X) break;
            cost %= MOD;
        }
        if (cost <= X) lo = mid;
        else hi = mid - 1;
    }

    // Double check if the current lo is the answer
    if (lo < hi) {
        lo = hi;
        if (dp[N - 1][lo % (A[N - 1].a * A[N - 1].b)] <= X) lo++;
    }

    printf("%lld\n", lo);
    return 0;
}