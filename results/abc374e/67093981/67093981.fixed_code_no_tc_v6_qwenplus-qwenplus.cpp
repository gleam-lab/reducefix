#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    int a, p, b, q;
} Printer;

Printer A[100];
long long dp[100][10000]; // dp[i][j] = min cost to print j pages on printer i

int N, X;

// Calculate the minimum cost for printer i to print n pages
long long cost(int i, int n) {
    int period = A[i].a * A[i].b;
    int d = n / period;
    int rem = n % period;
    return dp[i][rem] + 1LL * d * A[i].p * A[i].b;
}

// Check if we can print 'n' pages within budget X
bool isPossible(int n) {
    long long totalCost = 0;
    for (int i = 0; i < N; i++) {
        totalCost += cost(i, n);
        if (totalCost > X)
            return false;
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
        
        // Ensure the configuration with better efficiency comes first
        if (1LL * a * q < 1LL * b * p) {
            swap(a, b);
            swap(p, q);
        }
        
        A[i] = {a, p, b, q};
        
        // Initialize DP for this printer
        dp[i][0] = 0;
        for (int j = 1; j <= a * b; j++) {
            dp[i][j] = dp[i][max(0, j - a)] + p;
            if (j >= b)
                dp[i][j] = min(dp[i][j], dp[i][j - b] + q);
        }
    }

    // Binary search over the number of pages
    int lo = 0;
    int hi = 2e6; // More than sufficient upper bound based on problem constraints
    int answer = 0;
    
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (isPossible(mid)) {
            answer = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    printf("%d\n", answer);
}