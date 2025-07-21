#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

typedef struct { int a, p, b, q; } Item;
Item A[100];
long long dp[100][10000];

int N, X;

// Calculate the minimum cost to obtain 'n' units of item using dynamic programming and repeating pattern
long long cost(int i, int n) {
    long long d = n / (A[i].a * A[i].b);
    long long rem = n % (A[i].a * A[i].b);
    return dp[i][rem] + d * (long long)A[i].p * A[i].b;
}

// Check if we can produce 'n' units within budget X
bool isPossible(int n) {
    long long totalCost = 0;
    for (int i = 0; i < N; i++) {
        totalCost += cost(i, n);
        if (totalCost > X) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    scanf("%d %d", &N, &X);

    for (int i = 0; i < N; i++) {
        int a, p, b, q;
        scanf("%d %d %d %d", &a, &p, &b, &q);
        
        // Ensure a*q >= b*p to maintain consistent ordering
        if (a * q < b * p) {
            swap(a, b);
            swap(p, q);
        }
        
        A[i] = {a, p, b, q};
        
        // Initialize DP for this item
        dp[i][0] = 0;
        for (int j = 1; j <= a * b; j++) {
            dp[i][j] = LLONG_MAX;
            if (j - a >= 0)
                dp[i][j] = min(dp[i][j], dp[i][j - a] + p);
            if (j - b >= 0)
                dp[i][j] = min(dp[i][j], dp[i][j - b] + q);
        }
    }

    // Binary search for maximum possible number of items
    int lo = 0;
    int hi = 1e9;
    int answer = 0;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (isPossible(mid)) {
            answer = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    printf("%d\n", answer);
    return 0;
}