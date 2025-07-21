#include <iostream>
#include <algorithm>
using namespace std;

typedef struct{int a,p,b,q;} p;
p A[100];
long long dp[100][10001];

int N,X;

long long cost(int i, int n) {
    long long full_cycles = n / (A[i].a * A[i].b);
    long long rem = n % (A[i].a * A[i].b);
    return full_cycles * min(A[i].p * A[i].b, A[i].q * A[i].a) + dp[i][rem];
}

bool f(int n) {
    long long total_cost = 0;
    for(int i = 0; i < N; i++) {
        total_cost += cost(i, n);
        if(total_cost > X) return false;
    }
    return true;
}

int main() {
    scanf("%d %d", &N, &X);

    for(int i = 0; i < N; i++) {
        scanf("%d %d %d %d", &A[i].a, &A[i].p, &A[i].b, &A[i].q);
        int max_ab = A[i].a * A[i].b;
        
        dp[i][0] = 0;
        for(int j = 1; j <= max_ab; j++) {
            dp[i][j] = 1e18;
            if(j >= A[i].a) dp[i][j] = min(dp[i][j], dp[i][j - A[i].a] + A[i].p);
            if(j >= A[i].b) dp[i][j] = min(dp[i][j], dp[i][j - A[i].b] + A[i].q);
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