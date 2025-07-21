#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } p;
p A[100];
long long dp[100][10001]; // dp[i][j] is the minimal cost to produce j items of type i

int N;
long long X;

long long cost(int i, int n) {
    if (n == 0) return 0;
    int ab = A[i].a * A[i].b;
    long long d = n / ab;
    int rem = n % ab;
    return d * min(A[i].p * A[i].b, A[i].q * A[i].a) + dp[i][rem];
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
        int a = A[i].a, p = A[i].p, b = A[i].b, q = A[i].q;
        int ab = a * b;
        dp[i][0] = 0;
        for (int j = 1; j <= ab; j++) {
            long long option1 = (j >= a) ? dp[i][j - a] + p : q * ((j + b - 1) / b);
            long long option2 = (j >= b) ? dp[i][j - b] + q : p * ((j + a - 1) / a);
            dp[i][j] = min(option1, option2);
        }
    }

    long long lo = 0, hi = X;
    while (lo < hi) {
        long long mid = lo + (hi - lo + 1) / 2;
        if (feasible(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    printf("%lld\n", lo);
    return 0;
}