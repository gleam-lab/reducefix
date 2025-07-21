#include <iostream>
#include <algorithm>
using namespace std;

typedef struct{int a,p,b,q;} p;
p A[100];
long long dp[100][10001]; // Increased size to handle up to a*b

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
        int a = A[i].a, p = A[i].p, b = A[i].b, q = A[i].q;
        
        // Initialize DP for this item
        dp[i][0] = 0;
        for(int j = 1; j <= a*b; j++) {
            long long option1 = (j >= a) ? dp[i][j - a] + p : q;
            long long option2 = (j >= b) ? dp[i][j - b] + q : p;
            dp[i][j] = min(option1, option2);
        }
    }

    int lo = 0, hi = X;
    int answer = 0;
    
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if(f(mid)) {
            answer = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    printf("%d\n", answer);
    return 0;
}