#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } Pair;
Pair A[100];
long long dp[100][10000];

int N, X;

long long cost(int i, int n) {
    long long d = n / (A[i].a * A[i].b);
    int rem = n % (A[i].a * A[i].b);
    return d * (long long)A[i].p * A[i].b + dp[i][rem];
}

bool feasible(int n) {
    long long totalCost = 0;
    for (int i = 0; i < N; ++i) {
        totalCost += cost(i, n);
        if (totalCost > X) return false;
    }
    return true;
}

int main() {
    cin >> N >> X;

    for (int i = 0; i < N; ++i) {
        int a, p, b, q;
        cin >> a >> p >> b >> q;
        if ((long long)a * q < (long long)b * p) {
            swap(a, b);
            swap(p, q);
        }
        A[i] = {a, p, b, q};

        // Precompute minimum cost for 0 to a*b-1 pills
        fill(dp[i], dp[i] + a * b, 0);
        for (int j = 1; j < a * b; ++j) {
            dp[i][j] = 1e18;
            if (j >= a) dp[i][j] = min(dp[i][j], dp[i][j - a] + p);
            if (j >= b) dp[i][j] = min(dp[i][j], dp[i][j - b] + q);
        }
    }

    int lo = 0, hi = 1e9;
    while (lo < hi) {
        int mid = (lo + hi + 1) >> 1;
        if (feasible(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    cout << lo << endl;
}