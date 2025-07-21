#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {int a, p, b, q;} p;
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

    for (int i = 0, a, b, p, q; i < N; i++) {
        scanf("%d %d %d %d", &a, &p, &b, &q);
        if (a * q < b * p) swap(a, b), swap(p, q);
        A[i] = {a, p, b, q};
        dp[i][0] = 0;
        for (int j = 1; j < a * b; j++) {
            dp[i][j] = min(dp[i][max(0, j - a)] + p, dp[i][max(0, j - b)] + q);
        }
    }

    int lo = 0, hi = 1e9;
    while (hi - lo > 1) {
        int mid = (hi + lo) >> 1;
        if (f(mid)) lo = mid;
        else hi = mid - 1;
    }

    if (lo != hi && f(lo + 1)) lo++;
    printf("%d\n", lo);
}