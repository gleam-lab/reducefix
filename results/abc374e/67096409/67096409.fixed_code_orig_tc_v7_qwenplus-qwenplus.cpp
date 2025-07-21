#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

typedef struct { int a, p, b, q; } Item;
Item A[100];
long long dp[100][10000];

int N, X;

long long cost(int i, int n) {
    int ab = A[i].a * A[i].b;
    long long d = n / ab;
    int rem = n % ab;
    return d * (long long)A[i].p * A[i].b + dp[i][rem];
}

bool is_possible(int n) {
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
        // Ensure a*q >= b*p to prefer a over b
        if (a * q < b * p) swap(a, b), swap(p, q);
        A[i] = {a, p, b, q};

        int ab = a * b;
        dp[i][0] = 0;
        for (int j = 1; j < ab; ++j) {
            long long val1 = (j >= a) ? dp[i][j - a] + p : LLONG_MAX / 2;
            long long val2 = (j >= b) ? dp[i][j - b] + q : LLONG_MAX / 2;
            dp[i][j] = min(val1, val2);
        }
    }

    int lo = 0, hi = 1e9;
    while (lo < hi) {
        int mid = (lo + hi + 1) >> 1;
        if (is_possible(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    printf("%d\n", lo);
}