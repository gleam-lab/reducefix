#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } p;
p A[100];
long long dp[100][10000];

int N, X;

long long cost(int i, int n) {
    long long ab = A[i].a * A[i].b;
    long long d = n / ab;
    long long rem = n % ab;
    return dp[i][rem] + d * A[i].p * A[i].b;
}

bool f(long long n) {
    long long ct = 0;
    for (int i = 0; i < N; i++) {
        ct += cost(i, n);
        if (ct > X) return false;
    }
    return true;
}

int main() {
    scanf("%d %d", &N, &X);

    for (int i = 0; i < N; i++) {
        int a, p, b, q;
        scanf("%d %d %d %d", &a, &p, &b, &q);
        if ((long long)a * q > (long long)b * p) {
            swap(a, b);
            swap(p, q);
        }
        A[i] = {a, p, b, q};
        for (int j = 1; j < a * b; j++) {
            long long op1 = (j >= a) ? dp[i][j - a] + p : p;
            long long op2 = (j >= b) ? dp[i][j - b] + q : q;
            dp[i][j] = min(op1, op2);
        }
    }

    long long lo = 0, hi = 1e18;
    long long ans = 0;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (f(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}