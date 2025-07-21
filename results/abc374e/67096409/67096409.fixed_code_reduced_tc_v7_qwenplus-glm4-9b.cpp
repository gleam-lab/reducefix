#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } p;
p A[100];
long long dp[100][10000];

int N, X;
long long cost(int i, int n) {
    long long d = n / (A[i].a * A[i].b), rem = n % (A[i].a * A[i].b);
    return dp[i][rem] + d * A[i].p * A[i].b;
}
bool f(int n) {
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
        scanf("%d %d %d %d", &A[i].a, &A[i].p, &A[i].b, &A[i].q);
        if (A[i].a * A[i].q < A[i].b * A[i].p) swap(A[i].a, A[i].b), swap(A[i].p, A[i].q);
        fill(dp[i], dp[i] + A[i].a * A[i].b, 1e18);
        dp[i][0] = 0;
        for (int j = 1; j < A[i].a * A[i].b; j++) {
            dp[i][j] = min(dp[i][max(0, j - A[i].a)] + A[i].p, dp[i][max(0, j - A[i].b)] + A[i].q);
        }
    }

    int lo = 0, hi = 1e9;
    while (hi - lo > 1) {
        int mid = (hi + lo) / 2;
        if (f(mid)) lo = mid;
        else hi = mid - 1;
    }

    if (lo != hi && f(lo + 1)) lo++;
    printf("%d\n", lo);

    return 0;
}