#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

typedef struct { int a, p, b, q; } Pattern;
Pattern A[100];
long long dp[100][10000];  // dp[i][j]: min cost to print j pages with pattern i

int N, X;

// Calculate the minimal cost for pattern i to produce n pages
long long cost(int i, int n) {
    int lcm = A[i].a * A[i].b;
    long long full_cycles = n / lcm;
    int remainder = n % lcm;
    return full_cycles * (A[i].p * A[i].b + A[i].q * A[i].a) - 
           (full_cycles > 0 ? dp[i][lcm] : 0) + dp[i][remainder];
}

// Check if we can print 'n' pages within budget X
bool is_possible(int n) {
    long long total_cost = 0;
    for (int i = 0; i < N; i++) {
        total_cost += cost(i, n);
        if (total_cost > X)
            return false;
    }
    return true;
}

int main() {
    cin >> N >> X;

    for (int i = 0; i < N; i++) {
        int a, p, b, q;
        cin >> a >> p >> b >> q;

        // Ensure that (a,p) is more cost-efficient than (b,q)
        if (a * q < b * p) {
            swap(a, b);
            swap(p, q);
        }

        A[i] = {a, p, b, q};
        
        // Initialize DP for this pattern
        dp[i][0] = 0;
        for (int j = 1; j <= a * b; j++) {
            dp[i][j] = LLONG_MAX;
            if (j >= a)
                dp[i][j] = min(dp[i][j], dp[i][j - a] + p);
            if (j >= b)
                dp[i][j] = min(dp[i][j], dp[i][j - b] + q);
        }
    }

    // Binary search for maximum number of pages possible
    int low = 0, high = 2e9;
    int answer = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (is_possible(mid)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << answer << endl;
}