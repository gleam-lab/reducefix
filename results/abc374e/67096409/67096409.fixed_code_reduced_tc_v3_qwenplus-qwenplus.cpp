#include <iostream>
#include <algorithm>
using namespace std;

typedef struct { int a, p, b, q; } Printer;
Printer A[100];
long long dp[100][10000];

int N, X;

// Calculate cost for printing 'n' pages using i-th printer
long long cost(int i, int n) {
    long long d = n / (A[i].a * A[i].b);
    int rem = n % (A[i].a * A[i].b);
    return dp[i][rem] + d * (long long)A[i].p * A[i].b;
}

// Check if we can print 'n' pages within budget X
bool isPossible(int n) {
    long long totalCost = 0;
    for (int i = 0; i < N; ++i) {
        totalCost += cost(i, n);
        if (totalCost > X) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    scanf("%d %d", &N, &X);

    for (int i = 0; i < N; ++i) {
        int a, b, p, q;
        scanf("%d %d %d %d", &a, &p, &b, &q);
        
        // Ensure a*q <= b*p to normalize the order
        if (a * q > b * p) {
            swap(a, b);
            swap(p, q);
        }
        A[i] = {a, p, b, q};

        // Precompute minimum cost for each remainder (0 to a*b-1)
        dp[i][0] = 0;
        for (int j = 1; j < a * b; ++j) {
            dp[i][j] = 1e18; // Initialize with large value
            if (j >= a) dp[i][j] = min(dp[i][j], dp[i][j - a] + p);
            if (j >= b) dp[i][j] = min(dp[i][j], dp[i][j - b] + q);
        }
    }

    // Binary search for maximum number of pages printable within budget
    int low = 0, high = 1e9;
    while (low < high) {
        int mid = (low + (long long)high + 1) / 2;
        if (isPossible(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    printf("%d\n", low);
    return 0;
}