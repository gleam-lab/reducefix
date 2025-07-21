#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } p;
p A[100];
long long dp[100][20001]; // Increased size to handle larger remainders

int N, X;

long long cost(int i, int n) {
    long long full_cycles = n / (A[i].a * A[i].b);
    long long rem = n % (A[i].a * A[i].b);
    // We need to ensure we're using the optimal combination for the remainder
    return full_cycles * A[i].p * A[i].b + dp[i][rem];
}

bool f(int n) {
    long long total_cost = 0;
    for (int i = 0; i < N; i++) {
        total_cost += cost(i, n);
        if (total_cost > X) return false;
    }
    return true;
}

int main() {
    scanf("%d %d", &N, &X);

    for (int i = 0; i < N; i++) {
        scanf("%d %d %d %d", &A[i].a, &A[i].p, &A[i].b, &A[i].q);
        // Sort the items based on cost-effectiveness
        if (1LL * A[i].p * A[i].b > 1LL * A[i].q * A[i].a) {
            swap(A[i].a, A[i].b);
            swap(A[i].p, A[i].q);
        }
        
        // Initialize DP for this item
        for (int j = 0; j <= A[i].a * A[i].b; j++) {
            dp[i][j] = 1LL << 60; // Initialize to infinity
        }
        dp[i][0] = 0;
        
        for (int j = 1; j <= A[i].a * A[i].b; j++) {
            if (j >= A[i].a) {
                dp[i][j] = min(dp[i][j], dp[i][j - A[i].a] + A[i].p);
            }
            if (j >= A[i].b) {
                dp[i][j] = min(dp[i][j], dp[i][j - A[i].b] + A[i].q);
            }
        }
    }

    int lo = 0, hi = 1e9;
    int best = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (f(mid)) {
            best = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    printf("%d\n", best);
    return 0;
}