#include <iostream>
#include <algorithm>
using namespace std;

typedef struct{int a,p,b,q;} p;
p A[100];
long long dp[100][10001]; // Increased size to handle a*b cases

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
    for(int i = 0; i < N; i++) {
        total_cost += cost(i, n);
        if(total_cost > X) return false;
    }
    return true;
}

int main() {
    scanf("%d %lld", &N, &X);

    for(int i = 0; i < N; i++) {
        scanf("%d %d %d %d", &A[i].a, &A[i].p, &A[i].b, &A[i].q);
        if(A[i].a * A[i].q < A[i].b * A[i].p) {
            swap(A[i].a, A[i].b);
            swap(A[i].p, A[i].q);
        }
        
        int ab = A[i].a * A[i].b;
        dp[i][0] = 0;
        for(int j = 1; j <= ab; j++) {
            long long option1 = (j >= A[i].a) ? dp[i][j - A[i].a] + A[i].p : A[i].p;
            long long option2 = (j >= A[i].b) ? dp[i][j - A[i].b] + A[i].q : A[i].q;
            dp[i][j] = min(option1, option2);
        }
    }

    long long lo = 0, hi = 1e18;
    while(lo < hi) {
        long long mid = lo + (hi - lo + 1) / 2;
        if(f(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    printf("%lld\n", lo);
    return 0;
}