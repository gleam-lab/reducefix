#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

typedef struct { int a, p, b, q; } p;
p A[100];
long long dp[100][10001];

int N, X;

long long cost(int i, int n) {
    int ab = A[i].a * A[i].b;
    long long d = n / ab;
    int rem = n % ab;
    return d * min(A[i].p * A[i].b, A[i].q * A[i].a) + dp[i][rem];
}

bool f(long long n) {
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
        int ab = A[i].a * A[i].b;
        for (int j = 0; j <= ab; j++) {
            dp[i][j] = LLONG_MAX;
        }
        dp[i][0] = 0;
        
        for (int j = 1; j <= ab; j++) {
            if (j >= A[i].a) {
                dp[i][j] = min(dp[i][j], dp[i][j - A[i].a] + A[i].p);
            }
            if (j >= A[i].b) {
                dp[i][j] = min(dp[i][j], dp[i][j - A[i].b] + A[i].q);
            }
        }
    }

    long long lo = 0, hi = 1e18;
    long long answer = 0;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        if (f(mid)) {
            answer = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    printf("%lld\n", answer);
    return 0;
}