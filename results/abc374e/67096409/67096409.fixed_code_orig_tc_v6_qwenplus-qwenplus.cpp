#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } p_t;
p_t A[100];
long long dp[100][10000];

int N, X;
long long cost(int i, int n) {
    long long d = n / (A[i].a * A[i].b);
    int rem = n % (A[i].a * A[i].b);
    return d * A[i].p * A[i].b + dp[A[i].a * A[i].b * i + rem];
}

bool f(int n) {
    long long ct = 0;
    for (int i = 0; i < N; i++) {
        ct += cost(i, n);
        if (ct > X)
            return false;
    }
    return true;
}

int main() {
    scanf("%d %d", &N, &X);

    for (int i = 0; i < N; i++) {
        int a, p, b, q;
        scanf("%d %d %d %d", &a, &p, &b, &q);
        if ((long long)a * q < (long long)b * p) {
            swap(a, b);
            swap(p, q);
        }
        A[i] = {a, p, b, q};

        // Flatten DP to single array for better cache performance
        long long* dpi = dp[i];
        dpi[0] = 0;
        for (int j = 1; j < a * b; j++) {
            dpi[j] = X + 1; // Initialize to large value
            if (j >= a) dpi[j] = min(dpi[j], dpi[j - a] + p);
            if (j >= b) dpi[j] = min(dpi[j], dpi[j - b] + q);
        }
    }

    int lo = 0, hi = 2e9;
    while (lo < hi) {
        int mid = (lo + hi + 1) >> 1;
        if (f(mid))
            lo = mid;
        else
            hi = mid - 1;
    }

    printf("%d\n", lo);
}