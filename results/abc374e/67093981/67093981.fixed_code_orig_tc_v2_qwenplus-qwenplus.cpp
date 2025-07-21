#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

typedef struct { int a, p, b, q; } Item;
Item A[100];
long long dp[100][10000];

int N;
long long X;

// Computes minimum cost to get 'n' units from i-th item using DP
long long cost(int i, int n) {
    int ab = A[i].a * A[i].b;
    int d = n / ab;
    int rem = n % ab;
    return 1LL * d * A[i].p * A[i].b + dp[i][rem];
}

// Checks if it's possible to buy 'n' total units within budget X
bool feasible(int n) {
    long long total = 0;
    for (int i = 0; i < N; ++i) {
        total += cost(i, n);
        if (total > X)
            return false;
    }
    return true;
}

int main() {
    scanf("%d %lld", &N, &X);

    double minUnitCost = 1e18;
    for (int i = 0; i < N; ++i) {
        int a, p, b, q;
        scanf("%d %d %d %d", &a, &p, &b, &q);
        // Normalize so that (a,p) is better or equal than (b,q)
        if (1LL * a * q < 1LL * b * p) {
            swap(a, b);
            swap(p, q);
        }
        A[i] = {a, p, b, q};

        // Precompute minimal cost for 0..a*b units
        fill(dp[i], dp[i] + a * b + 1, LLONG_MAX / 2);
        dp[i][0] = 0;
        for (int j = 1; j <= a * b; ++j) {
            if (j >= a) dp[i][j] = min(dp[i][j], dp[i][j - a] + p);
            if (j >= b) dp[i][j] = min(dp[i][j], dp[i][j - b] + q);
        }

        // Update minimum cost per unit
        double unitCost = 1.0 * dp[i][a * b] / (a * b);
        minUnitCost = min(minUnitCost, unitCost);
    }

    // Compute max possible number of units we can afford
    int maxPossible = X / minUnitCost + 200; // add buffer

    // Binary search
    int lo = 0, hi = maxPossible;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (feasible(mid))
            lo = mid;
        else
            hi = mid - 1;
    }

    printf("%d\n", lo);
}