#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } Offer;
Offer offers[100];
long long dp[100][10001];  // dp[i][j] = min cost to buy j items using offers[0..i]

int N, X;

long long compute_cost(int n) {
    long long total_cost = 0;
    for (int i = 0; i < N; i++) {
        int a = offers[i].a, p = offers[i].p;
        int b = offers[i].b, q = offers[i].q;
        
        // Number of full a*b bundles
        long long bundles = n / (a * b);
        long long remaining = n % (a * b);
        
        // Cost from full bundles
        long long bundle_cost = bundles * min(a * q, b * p);
        
        // Cost from remaining items
        long long rem_cost = min(
            (remaining / a) * p + (remaining % a) * min(p, q),
            (remaining / b) * q + (remaining % b) * min(p, q)
        );
        
        total_cost += bundle_cost + rem_cost;
        if (total_cost > X) return total_cost;
    }
    return total_cost;
}

int main() {
    scanf("%d %d", &N, &X);
    
    for (int i = 0; i < N; i++) {
        int a, p, b, q;
        scanf("%d %d %d %d", &a, &p, &b, &q);
        // Compare cost per unit for better offer
        if ((double)p/a > (double)q/b) {
            swap(a, b);
            swap(p, q);
        }
        offers[i] = {a, p, b, q};
    }
    
    int lo = 0, hi = X;
    int answer = 0;
    
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (compute_cost(mid) <= X) {
            answer = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    
    printf("%d\n", answer);
    return 0;
}