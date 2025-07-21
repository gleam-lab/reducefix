#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } p;
p A[100];
long long dp[100][10000];

int N, X;

long long cost(int i, int n) {
    if (n == 0) return 0;
    long long d = n / (A[i].a * A[i].b);
    long long rem = n % (A[i].a * A[i].b);
    return dp[i][rem] + d * A[i].p * A[i].b;
}

bool f(int n) {
    long long total = 0;
    for (int i = 0; i < N; i++) {
        total += cost(i, n);
        if (total > X) return false;
    }
    return true;
}

int main() {
    scanf("%d %d", &N, &X);

    for (int i = 0; i < N; i++) {
        scanf("%d %d %d %d", &A[i].a, &A[i].p, &A[i].b, &A[i].q);
        if (A[i].a * A[i].q < A[i].b * A[i].p) {
            swap(A[i].a, A[i].b);
            swap(A[i].p, A[i].q);
        }
        dp[i][0] = 0;
        for (int j = 1; j <= A[i].a * A[i].b; j++) {
            long long option1 = (j >= A[i].a) ? dp[i][j - A[i].a] + A[i].p : LLONG_MAX;
            long long option2 = (j >= A[i].b) ? dp[i][j - A[i].b] + A[i].q : LLONG_MAX;
            dp[i][j] = min(option1, option2);
        }
    }

    int lo = 0, hi = 1e9;
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (f(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    printf("%d\n", lo);
    return 0;
}