#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

typedef struct { int a, p, b, q; } Item;
Item A[100];
long long dp[100][10000];

int N, X;

// Calculate the minimum cost to achieve 'n' units using either of the two package sizes for item i
long long cost(int i, int n) {
    long long d = n / (A[i].a * A[i].b);
    int rem = n % (A[i].a * A[i].b);
    return dp[i][rem] + d * (long long)A[i].p * A[i].b;
}

// Check if it's possible to buy at least 'n' total items within budget X
bool feasible(int n) {
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

    cin >> N >> X;

    for (int i = 0; i < N; i++) {
        int a, p, b, q;
        cin >> a >> p >> b >> q;
        
        // Ensure that (a,p) is the more cost-effective single unit option
        if (a * q < b * p) {
            swap(a, b);
            swap(p, q);
        }

        A[i] = {a, p, b, q};

        dp[i][0] = 0;
        for (int j = 1; j < a * b; j++) {
            dp[i][j] = LLONG_MAX;
            if (j - a >= 0)
                dp[i][j] = min(dp[i][j], dp[i][j - a] + p);
            if (j - b >= 0)
                dp[i][j] = min(dp[i][j], dp[i][j - b] + q);
        }
    }

    // Binary search for maximum number of items that can be bought
    int lo = 0, hi = 1e9;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (feasible(mid)) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    // After loop, lo is first infeasible value, so lo-1 is max feasible
    if (feasible(lo)) {
        cout << lo << "\n";
    } else {
        cout << lo - 1 << "\n";
    }

    return 0;
}