#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } p;
p A[100];
long long dp[100][10000];

int N;
long long X;

long long cost(int i, long long n) {
    long long ab = (long long)A[i].a * A[i].b;
    long long d = n / ab;
    long long rem = n % ab;
    return dp[i][rem] + d * A[i].p * A[i].b;
}

bool f(long long n) {
    long long total_cost = 0;
    for (int i = 0; i < N; ++i) {
        total_cost += cost(i, n);
        if (total_cost > X) return false;
    }
    return true;
}

int main() {
    scanf("%d %lld", &N, &X);

    for (int i = 0; i < N; ++i) {
        int a, p, b, q;
        scanf("%d %d %d %d", &a, &p, &b, &q);
        if ((long long)a * q < (long long)b * p) {
            swap(a, b);
            swap(p, q);
        }
        A[i] = {a, p, b, q};

        dp[i][0] = 0;
        for (int j = 1; j < a * b; ++j) {
            long long option1 = (j >= a) ? dp[i][j - a] + p : p;
            long long option2 = (j >= b) ? dp[i][j - b] + q : q;
            dp[i][j] = min(option1, option2);
        }
    }

    long long lo = 0, hi = 1e18;
    if (!f(lo)) {
        printf("0\n");
        return 0;
    }

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