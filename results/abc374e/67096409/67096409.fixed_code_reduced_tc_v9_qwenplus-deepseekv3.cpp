#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } p;
p A[100];
long long dp[100][10000];

int N, X;

long long cost(int i, int n) {
    long long d = n / (A[i].a * A[i].b);
    long long rem = n % (A[i].a * A[i].b);
    return dp[i][rem] + d * A[i].p * A[i].b;
}

bool f(int n) {
    long long ct = 0;
    for (int i = 0; i < N; i++) {
        ct += cost(i, n);
        if (ct > X) return false;
    }
    return ct <= X;
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
        
        dp[i][0] = 0;
        for (int j = 1; j < a * b; j++) {
            long long option1 = (j >= a) ? dp[i][j - a] + p : p;
            long long option2 = (j >= b) ? dp[i][j - b] + q : q;
            dp[i][j] = min(option1, option2);
        }
    }

    int lo = 0, hi = X;
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