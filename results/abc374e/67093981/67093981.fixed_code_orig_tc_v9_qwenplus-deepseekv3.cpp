#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } p;
p A[100];
long long dp[100][10001];  // Adjusted size to avoid out-of-bounds access

int N, X;

long long cost(int i, int n) {
    long long ab = A[i].a * A[i].b;
    long long d = n / ab;
    long long rem = n % ab;
    return dp[i][rem] + d * min(A[i].p * A[i].b, A[i].q * A[i].a);
}

bool feasible(int n) {
    long long total_cost = 0;
    for (int i = 0; i < N; ++i) {
        total_cost += cost(i, n);
        if (total_cost > X) return false;
    }
    return true;
}

int main() {
    scanf("%d %d", &N, &X);

    for (int i = 0; i < N; ++i) {
        int a, p, b, q;
        scanf("%d %d %d %d", &a, &p, &b, &q);
        A[i] = {a, p, b, q};
        int ab = a * b;
        dp[i][0] = 0;
        for (int j = 1; j <= ab; ++j) {
            long long option1 = (j >= a) ? dp[i][j - a] + p : q + dp[i][max(0, j - b)];  // Fixed to handle initial cases correctly
            long long option2 = (j >= b) ? dp[i][j - b] + q : p + dp[i][max(0, j - a)];  // Ensure both options are considered
            dp[i][j] = min(option1, option2);
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