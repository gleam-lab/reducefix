#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } p;
p A[100];
long long dp[100][20001]; // Increased size to handle larger remainders

int N;
long long X;

long long cost(int i, int n) {
    int ab = A[i].a * A[i].b;
    long long d = n / ab;
    int rem = n % ab;
    return d * min(A[i].p * A[i].b, A[i].q * A[i].a) + dp[i][rem];
}

bool f(int n) {
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
        int a, p, b, q;
        scanf("%d %d %d %d", &a, &p, &b, &q);
        A[i] = {a, p, b, q};
        
        // Initialize DP table for this item
        dp[i][0] = 0;
        for (int j = 1; j <= 2 * a * b; j++) {
            long long option1 = (j >= a) ? dp[i][j - a] + p : q;
            long long option2 = (j >= b) ? dp[i][j - b] + q : p;
            dp[i][j] = min(option1, option2);
        }
    }

    int lo = 0, hi = 1e9;
    int ans = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (f(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    printf("%d\n", ans);
    return 0;
}