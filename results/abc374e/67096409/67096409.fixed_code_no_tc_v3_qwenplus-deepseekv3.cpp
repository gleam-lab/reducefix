#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } p;
p A[100];
long long dp[100][20001]; // Increased size to handle larger remainders

int N;
long long X;

long long cost(int i, int n) {
    if (n == 0) return 0;
    int ab = A[i].a * A[i].b;
    long long d = n / ab;
    int rem = n % ab;
    return d * A[i].p * A[i].b + dp[i][rem];
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
    scanf("%d %lld", &N, &X);

    for (int i = 0; i < N; i++) {
        scanf("%d %d %d %d", &A[i].a, &A[i].p, &A[i].b, &A[i].q);
        if (A[i].a * A[i].q < A[i].b * A[i].p) {
            swap(A[i].a, A[i].b);
            swap(A[i].p, A[i].q);
        }
        
        int ab = A[i].a * A[i].b;
        for (int j = 0; j <= ab; j++) {
            dp[i][j] = (j == 0) ? 0 : LLONG_MAX;
            if (j >= A[i].a) dp[i][j] = min(dp[i][j], dp[i][j - A[i].a] + A[i].p);
            if (j >= A[i].b) dp[i][j] = min(dp[i][j], dp[i][j - A[i].b] + A[i].q);
        }
    }

    long long lo = 0, hi = X;
    while (lo < hi) {
        long long mid = lo + (hi - lo + 1) / 2;
        if (f(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    printf("%lld\n", lo);
    return 0;
}