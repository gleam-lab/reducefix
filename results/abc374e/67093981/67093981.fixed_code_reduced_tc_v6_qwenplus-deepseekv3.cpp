#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } ProductionOption;
ProductionOption A[100];
long long dp[100][10001];  // Increased size to handle up to a*b

int N;
long long X;

long long cost(int i, int n) {
    if (n == 0) return 0;
    long long d = n / (A[i].a * A[i].b);
    long long rem = n % (A[i].a * A[i].b);
    return dp[i][rem] + d * A[i].p * A[i].b;
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
        // Ensure the more cost-effective option is considered first
        if (A[i].p * A[i].b > A[i].q * A[i].a) {
            swap(A[i].a, A[i].b);
            swap(A[i].p, A[i].q);
        }
        
        // Initialize DP for this production option
        dp[i][0] = 0;
        for (int j = 1; j <= A[i].a * A[i].b; j++) {
            dp[i][j] = min(
                (j >= A[i].a) ? dp[i][j - A[i].a] + A[i].p : LLONG_MAX,
                (j >= A[i].b) ? dp[i][j - A[i].b] + A[i].q : LLONG_MAX
            );
        }
    }

    int lo = 0, hi = 1e9;
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (feasible(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    printf("%d\n", lo);
    return 0;
}