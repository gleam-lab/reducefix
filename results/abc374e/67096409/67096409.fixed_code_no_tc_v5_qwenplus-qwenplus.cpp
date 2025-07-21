#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    int a, p, b, q;
} Printer;

Printer A[100];
long long dp[100][10000]; // dp[i][j] = min cost to print j pages with printer i

int N, X;

// Calculate the minimal cost for printer i to print n pages
long long cost(int i, int n) {
    int cycle = A[i].a * A[i].b;
    long long full_cycles = n / cycle;
    int remainder = n % cycle;
    return dp[i][remainder] + full_cycles * (A[i].p * A[i].b);
}

// Check if we can print 'n' total pages within budget X
bool isPossible(int n) {
    long long total = 0;
    for (int i = 0; i < N; i++) {
        total += cost(i, n);
        if (total > X) return false;
    }
    return true;
}

int main() {
    cin >> N >> X;

    for (int i = 0; i < N; i++) {
        int a, p, b, q;
        cin >> a >> p >> b >> q;
        
        // Ensure a*q >= b*p for better price/page ratio
        if (a * q < b * p) {
            swap(a, b);
            swap(p, q);
        }
        A[i] = {a, p, b, q};
        
        // Initialize dp for this printer
        dp[i][0] = 0;
        for (int j = 1; j < a * b; j++) {
            dp[i][j] = 1e18; // Set to large value initially
            if (j - a >= 0)
                dp[i][j] = min(dp[i][j], dp[i][j - a] + p);
            if (j - b >= 0)
                dp[i][j] = min(dp[i][j], dp[i][j - b] + q);
        }
    }

    // Binary search for maximum possible total pages
    int lo = 0, hi = 1e6; // Adjusted upper bound to be more reasonable
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

    cout << answer << endl;
    return 0;
}