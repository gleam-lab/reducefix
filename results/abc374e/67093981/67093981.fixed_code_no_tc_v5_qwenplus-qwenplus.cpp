#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
using namespace std;

typedef struct { int a, p, b, q; } Machine;
Machine A[100];
long long dp[100][10000];  // dp[i][j]: min cost to produce j units using machine i

int N, X;

// Calculate the minimum cost to produce 'n' units on machine 'i'
long long cost(int i, int n) {
    int period = A[i].a * A[i].b;
    int d = n / period;
    int rem = n % period;
    return (long long)d * A[i].p * A[i].b + dp[i][rem];
}

// Check if it's possible to produce 'n' units within budget X
bool isPossible(int n) {
    long long totalCost = 0;
    for (int i = 0; i < N; i++) {
        totalCost += cost(i, n);
        if (totalCost > X)
            return false;
    }
    return true;
}

int main() {
    scanf("%d %d", &N, &X);

    for (int i = 0; i < N; i++) {
        int a, p, b, q;
        scanf("%d %d %d %d", &a, &p, &b, &q);

        // Ensure the first option is more efficient per unit
        if (a * q < b * p) {
            swap(a, b);
            swap(p, q);
        }

        A[i] = {a, p, b, q};
        int period = a * b;

        dp[i][0] = 0;
        for (int j = 1; j <= period; j++) {
            dp[i][j] = LLONG_MAX;
            if (j >= a)
                dp[i][j] = min(dp[i][j], dp[i][j - a] + p);
            if (j >= b)
                dp[i][j] = min(dp[i][j], dp[i][j - b] + q);
        }
    }

    // Binary search for maximum number of units that can be produced
    int lo = 0, hi = 1e9;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (isPossible(mid))
            lo = mid;
        else
            hi = mid - 1;
    }

    printf("%d\n", lo);
    return 0;
}