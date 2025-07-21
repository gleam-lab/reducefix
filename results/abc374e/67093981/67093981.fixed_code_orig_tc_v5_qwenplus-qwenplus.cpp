#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

typedef struct { int a, p, b, q; } Package;
Package packages[100];
long long dp[100][10000];

int N, X;

// Calculate the minimum cost to get 'n' items from the i-th package
long long cost(int i, int n) {
    Package pkg = packages[i];
    int period = pkg.a * pkg.b;
    long long full_cycles = n / period;
    int remainder = n % period;
    return full_cycles * (long long)pkg.p * pkg.b + dp[i][remainder];
}

// Check if we can buy at least 'n' items within budget X
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
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N >> X;

    for (int i = 0; i < N; i++) {
        int a, p, b, q;
        cin >> a >> p >> b >> q;
        
        // Ensure cheaper option per unit comes first
        if (a * q < b * p) {
            swap(a, b);
            swap(p, q);
        }

        packages[i] = {a, p, b, q};
        int period = a * b;

        // Initialize DP for this package
        dp[i][0] = 0;
        for (int j = 1; j < period; j++) {
            dp[i][j] = LLONG_MAX;
            if (j >= a)
                dp[i][j] = min(dp[i][j], dp[i][j - a] + p);
            if (j >= b)
                dp[i][j] = min(dp[i][j], dp[i][j - b] + q);
        }
    }

    // Binary search for maximum number of items we can buy
    int low = 0, high = 1e9;
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