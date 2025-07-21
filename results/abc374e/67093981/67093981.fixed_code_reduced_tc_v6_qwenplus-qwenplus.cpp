#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef struct { int a, p, b, q; } Item;
vector<Item> items;
vector<vector<long long>> dp;

int N, X;

long long cost(int i, int n) {
    long long d = n / (items[i].a * items[i].b);
    int rem = n % (items[i].a * items[i].b);
    return dp[i][rem] + d * (long long)items[i].p * items[i].b;
}

bool isPossible(int target) {
    long long totalCost = 0;
    for (int i = 0; i < N; ++i) {
        totalCost += cost(i, target);
        if (totalCost > X)
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> X;
    items.resize(N);
    dp.resize(N);

    for (int i = 0; i < N; ++i) {
        int a, p, b, q;
        cin >> a >> p >> b >> q;
        
        // Ensure we pick the cheaper per-unit option first
        if (a * q < b * p) {
            swap(a, b);
            swap(p, q);
        }
        
        items[i] = {a, p, b, q};
        int maxPattern = a * b;
        dp[i].assign(maxPattern + 1, LLONG_MAX / 2);
        dp[i][0] = 0;
        
        // Fill DP for this item's cost pattern
        for (int j = 1; j <= maxPattern; ++j) {
            long long costA = (j - a >= 0) ? dp[i][j - a] + p : LLONG_MAX / 2;
            long long costB = (j - b >= 0) ? dp[i][j - b] + q : LLONG_MAX / 2;
            dp[i][j] = min(dp[i][j], min(costA, costB));
        }
    }

    // Binary search for maximum number of pills that can be bought
    int low = 0, high = 1e9;
    int answer = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(mid)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << answer << endl;
    return 0;
}