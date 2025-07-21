#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

typedef struct { int a, p, b, q; } Machine;

const int MAX_MACHINES = 100;
const int MAX_MOD = 10000; // Must be at least 100*100 for the dp array indexing
Machine A[MAX_MACHINES];
long long dp[MAX_MACHINES][MAX_MOD];

int N, X;

// Calculates the cost to produce 'n' units on machine 'i'
long long cost(int i, int n) {
    int period = A[i].a * A[i].b;
    int d = n / period;
    int rem = n % period;
    return 1LL * d * A[i].p * A[i].b + dp[i][rem];
}

// Checks if it's possible to produce 'n' units within budget X
bool isPossible(int n) {
    long long totalCost = 0;
    for (int i = 0; i < N; i++) {
        totalCost += cost(i, n);
        if (totalCost > X) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    scanf("%d %d", &N, &X);

    for (int i = 0; i < N; i++) {
        int a, p, b, q;
        scanf("%d %d %d %d", &a, &p, &b, &q);
        
        // Ensure a*q >= b*p to make sure we use optimal order in DP
        if (a * q < b * p) {
            swap(a, b);
            swap(p, q);
        }
        A[i] = {a, p, b, q};
        
        dp[i][0] = 0;
        for (int j = 1; j < a * b; j++) {
            dp[i][j] = LLONG_MAX;
            if (j >= a) {
                dp[i][j] = min(dp[i][j], dp[i][j - a] + p);
            }
            if (j >= b) {
                dp[i][j] = min(dp[i][j], dp[i][j - b] + q);
            }
        }
    }

    // Binary search for maximum number of units
    int lo = 0, hi = 1e9;
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (isPossible(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    printf("%d\n", lo);
}