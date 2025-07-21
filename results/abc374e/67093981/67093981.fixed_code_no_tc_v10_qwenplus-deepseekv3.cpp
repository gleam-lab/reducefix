#include <iostream>
#include <algorithm>
using namespace std;

typedef struct{int a,p,b,q;} p;
p A[100];
long long dp[100][10001]; // Increased size to handle up to a*b

int N,X;

long long cost(int i, int n) {
    int ab = A[i].a * A[i].b;
    long long full_cycles = n / ab;
    int rem = n % ab;
    
    // Cost is full_cycles * (optimal cost for ab items) + cost for remaining
    return full_cycles * dp[i][ab] + dp[i][rem];
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
        int a, p, b, q;
        scanf("%d %d %d %d", &a, &p, &b, &q);
        
        // Compare a*q and b*p to determine which is better
        if(1LL * a * q > 1LL * b * p) {
            swap(a, b);
            swap(p, q);
        }
        A[i] = {a, p, b, q};
        
        // Initialize DP for this item
        dp[i][0] = 0;
        for(int j = 1; j <= a*b; j++) {
            long long option1 = (j >= a) ? dp[i][j - a] + p : 1LL << 60;
            long long option2 = (j >= b) ? dp[i][j - b] + q : 1LL << 60;
            dp[i][j] = min(option1, option2);
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