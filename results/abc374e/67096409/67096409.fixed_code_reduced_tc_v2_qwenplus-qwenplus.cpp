#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

typedef struct { int a, p, b, q; } Item;
Item A[100];
long long dp[100][10000];

int N, X;

// Calculate the minimum cost to obtain 'n' units of item i
long long cost(int i, int n) {
    if (n == 0) return 0;
    long long d = n / (A[i].a * A[i].b);
    int rem = n % (A[i].a * A[i].b);
    return dp[i][rem] + d * (long long)A[i].p * A[i].b;
}

// Check if we can buy at least 'n' total items within budget X
bool feasible(int n) {
    long long total_cost = 0;
    for (int i = 0; i < N; ++i) {
        int item_count = n;
        long long item_cost = cost(i, item_count);
        total_cost += item_cost;
        if (total_cost > X)
            return false;
    }
    return true;
}

int main() {
    cin >> N >> X;

    // Precompute minimal cost for each item up to a*b using DP
    for (int i = 0; i < N; ++i) {
        int a, p, b, q;
        cin >> a >> p >> b >> q;

        // Ensure better value item is first
        if (a * q < b * p) {
            swap(a, b);
            swap(p, q);
        }

        A[i] = {a, p, b, q};

        // Initialize DP table for this item
        dp[i][0] = 0;
        for (int j = 1; j < a * b; ++j) {
            dp[i][j] = LLONG_MAX;
            if (j - a >= 0)
                dp[i][j] = min(dp[i][j], dp[i][j - a] + p);
            if (j - b >= 0)
                dp[i][j] = min(dp[i][j], dp[i][j - b] + q);
        }
    }

    // Binary search for maximum number of items we can buy
    int low = 0, high = 1e9;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (feasible(mid)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << high << endl;
}