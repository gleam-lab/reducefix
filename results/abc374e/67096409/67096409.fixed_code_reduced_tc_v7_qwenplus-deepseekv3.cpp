#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

typedef struct { int a, p, b, q; } p;
p A[100];
long long dp[100][10000];

int N, X;

long long cost(int i, long long n) {
    long long d = n / (A[i].a * A[i].b);
    long long rem = n % (A[i].a * A[i].b);
    return dp[i][rem] + d * A[i].p * A[i].b;
}

bool f(long long n) {
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
        int a, p, b, q;
        scanf("%d %d %d %d", &a, &p, &b, &q);
        if (a * q < b * p) {
            swap(a, b);
            swap(p, q);
        }
        A[i] = {a, p, b, q};
        dp[i][0] = 0;
        for (int j = 1; j < a * b; j++) {
            long long option1 = (j >= a) ? dp[i][j - a] + p : p;
            long long option2 = (j >= b) ? dp[i][j - b] + q : q;
            dp[i][j] = min(option1, option2);
        }
    }

    long long lo = 0, hi = 1e18;
    long long answer = 0;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (f(mid)) {
            answer = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    printf("%lld\n", answer);
    return 0;
}