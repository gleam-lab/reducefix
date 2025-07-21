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
    return dp[i][rem] + d * (long long)A[i].p * A[i].b;
}

bool feasible(int n) {
    long long total_cost = 0;
    for (int i = 0; i < N; ++i) {
        total_cost += cost(i, n);
        if (total_cost > X)
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    scanf("%d %d", &N, &X);

    for (int i = 0; i < N; ++i) {
        int a, p, b, q;
        scanf("%d %d %d %d", &a, &p, &b, &q);
        
        // Ensure we use the more cost-effective option first
        if ((long long)a * q < (long long)b * p) {
            swap(a, b);
            swap(p, q);
        }
        A[i] = {a, p, b, q};

        dp[i][0] = 0;
        for (int j = 1; j < a * b; ++j) {
            dp[i][j] = min(
                dp[i][max(0, j - a)] + p,
                dp[i][max(0, j - b)] + q
            );
        }
    }

    int lo = 0, hi = 1e9;
    while (hi - lo > 1) {
        int mid = (hi + lo) >> 1;
        if (feasible(mid))
            lo = mid;
        else
            hi = mid - 1;
    }

    if (lo != hi && feasible(lo + 1))
        lo++;

    printf("%d\n", lo);

    return 0;
}