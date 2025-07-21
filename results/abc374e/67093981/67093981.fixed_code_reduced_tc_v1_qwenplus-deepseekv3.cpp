#include <iostream>
#include <climits>
using namespace std;

typedef struct{int a,p,b,q;} p;
p A[100];
long long dp[100][10001];

int N,X;

long long cost(int i, int n) {
    long long d = n / (A[i].a * A[i].b);
    int rem = n % (A[i].a * A[i].b);
    return dp[i][rem] + d * A[i].p * A[i].b;
}

bool f(int n) {
    long long ct = 0;
    for(int i = 0; i < N; i++) {
        ct += cost(i, n);
        if(ct > X) return false;
    }
    return true;
}

int main() {
    scanf("%d %d", &N, &X);

    for(int i = 0; i < N; i++) {
        scanf("%d %d %d %d", &A[i].a, &A[i].p, &A[i].b, &A[i].q);
        if((long long)A[i].a * A[i].q > (long long)A[i].b * A[i].p) {
            swap(A[i].a, A[i].b);
            swap(A[i].p, A[i].q);
        }
        
        for(int j = 0; j <= A[i].a * A[i].b; j++) {
            dp[i][j] = LLONG_MAX;
        }
        dp[i][0] = 0;
        
        for(int j = 1; j <= A[i].a * A[i].b; j++) {
            if(j >= A[i].a && dp[i][j - A[i].a] != LLONG_MAX) {
                dp[i][j] = min(dp[i][j], dp[i][j - A[i].a] + A[i].p);
            }
            if(j >= A[i].b && dp[i][j - A[i].b] != LLONG_MAX) {
                dp[i][j] = min(dp[i][j], dp[i][j - A[i].b] + A[i].q);
            }
        }
    }

    int lo = 0, hi = 1e9;
    int ans = 0;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if(f(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    printf("%d\n", ans);
    return 0;
}