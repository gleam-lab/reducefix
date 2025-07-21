#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } Machine;
Machine A[100];
long long dp[100][10000];  // dp[i][j] = min cost to get j units of product from machine i

int N, X;

// Calculates the minimum cost to produce 'n' units using machine i
long long cost(int i, int n) {
    long long d = n / (A[i].a * A[i].b);
    long long rem = n % (A[i].a * A[i].b);
    return dp[i][rem] + d * (long long)A[i].p * A[i].b;
}

// Checks if it's possible to produce 'n' units within budget X
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

        // Ensure the first option is more cost-effective per unit
        if (a * q < b * p) {
            swap(a, b);
            swap(p, q);
        }

        A[i] = {a, p, b, q};

        // Precompute minimum cost for each possible amount up to a*b
        dp[i][0] = 0;
        for (int j = 1; j < a * b; j++) {
            dp[i][j] = dp[i][max(0, j - a)] + p;
            if (j >= b)
                dp[i][j] = min(dp[i][j], dp[i][j - b] + q);
        }
    }

    // Binary search for maximum number of units we can produce
    int lo = 0;
    int hi = 2e9;  // Increase range slightly
    while (lo < hi) {
        int mid = (long long)lo + (hi - lo + 1) / 2;
        if (isPossible(mid))
            lo = mid;
        else
            hi = mid - 1;
    }

    printf("%d\n", lo);
}