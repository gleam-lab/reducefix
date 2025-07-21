#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

typedef struct{int a,p,b,q;} p;
p A[100];
long long dp[100][10001]; // Increased size to handle larger remainders

int N,X;

long long cost(int i, int n) {
    int ab = A[i].a * A[i].b;
    long long d = n / ab;
    int rem = n % ab;
    return d * min(A[i].p * A[i].b, A[i].q * A[i].a) + dp[i][rem];
}

bool f(int n) {
    long long ct = 0;
    for(int i = 0; i < N; i++) {
        ct += cost(i, n);
        if(ct > X) return false;
    }
    return ct <= X;
}

int main() {
    scanf("%d %d", &N, &X);

    for(int i = 0; i < N; i++) {
        scanf("%d %d %d %d", &A[i].a, &A[i].p, &A[i].b, &A[i].q);
        // Initialize DP for this item
        int ab = A[i].a * A[i].b;
        for(int j = 0; j <= ab; j++) {
            dp[i][j] = LLONG_MAX;
        }
        dp[i][0] = 0;
        for(int j = 1; j <= ab; j++) {
            if(j >= A[i].a) dp[i][j] = min(dp[i][j], dp[i][j - A[i].a] + A[i].p);
            if(j >= A[i].b) dp[i][j] = min(dp[i][j], dp[i][j - A[i].b] + A[i].q);
        }
        // Fill any remaining unreachable values with the best possible
        for(int j = 1; j <= ab; j++) {
            if(dp[i][j] == LLONG_MAX) {
                dp[i][j] = dp[i][j-1];
            } else if(j > 0) {
                dp[i][j] = min(dp[i][j], dp[i][j-1]);
            }
        }
    }

    int lo = 0, hi = X;
    while(lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if(f(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    printf("%d\n", lo);
    return 0;
}