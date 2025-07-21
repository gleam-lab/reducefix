#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } Package;
Package A[100];
long long dp[100][10001]; // Increased size to handle larger remainders

int N;
long long X;

long long cost(int i, int n) {
    if (n == 0) return 0;
    long long full_cycles = n / (A[i].a * A[i].b);
    long long remainder = n % (A[i].a * A[i].b);
    return full_cycles * min(A[i].p * A[i].b, A[i].q * A[i].a) + dp[i][remainder];
}

bool feasible(int n) {
    long long total_cost = 0;
    for (int i = 0; i < N; i++) {
        total_cost += cost(i, n);
        if (total_cost > X) return false;
    }
    return true;
}

int main() {
    scanf("%d %lld", &N, &X);

    for (int i = 0; i < N; i++) {
        scanf("%d %d %d %d", &A[i].a, &A[i].p, &A[i].b, &A[i].q);
        // Initialize DP table for this package
        for (int j = 0; j <= A[i].a * A[i].b; j++) {
            if (j == 0) {
                dp[i][j] = 0;
                continue;
            }
            long long option1 = (j >= A[i].a) ? dp[i][j - A[i].a] + A[i].p : LLONG_MAX;
            long long option2 = (j >= A[i].b) ? dp[i][j - A[i].b] + A[i].q : LLONG_MAX;
            dp[i][j] = min(option1, option2);
        }
    }

    long long lo = 0, hi = X;
    while (lo < hi) {
        long long mid = lo + (hi - lo + 1) / 2;
        if (feasible(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    printf("%lld\n", lo);
    return 0;
}