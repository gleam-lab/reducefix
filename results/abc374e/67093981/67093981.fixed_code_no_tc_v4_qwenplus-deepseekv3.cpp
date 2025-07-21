#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } Production;
Production A[100];
long long dp[100][10001];  // Increased size to handle larger a*b products

int N, X;

long long cost(int i, int n) {
    int ab = A[i].a * A[i].b;
    long long d = n / ab;
    int rem = n % ab;
    return dp[i][rem] + d * min(A[i].p * A[i].b, A[i].q * A[i].a);
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
    scanf("%d %d", &N, &X);

    for (int i = 0; i < N; i++) {
        scanf("%d %d %d %d", &A[i].a, &A[i].p, &A[i].b, &A[i].q);
        // Initialize DP table for this item
        int ab = A[i].a * A[i].b;
        dp[i][0] = 0;
        for (int j = 1; j <= ab; j++) {
            long long op1 = (j >= A[i].a) ? dp[i][j - A[i].a] + A[i].p : A[i].p;
            long long op2 = (j >= A[i].b) ? dp[i][j - A[i].b] + A[i].q : A[i].q;
            dp[i][j] = min(op1, op2);
        }
    }

    int lo = 0, hi = X;  // More reasonable upper bound
    int answer = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (feasible(mid)) {
            answer = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    printf("%d\n", answer);
    return 0;
}