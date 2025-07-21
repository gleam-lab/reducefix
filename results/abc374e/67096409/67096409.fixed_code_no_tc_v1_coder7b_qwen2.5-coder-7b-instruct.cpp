#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Machine {
    int a, p, b, q; // Production rate, cost per unit for machines S and T respectively
};

// Function to calculate the minimum production capacity with given budget
int maxProductionCapacity(const vector<Machine>& machines, int budget) {
    int n = machines.size();
    vector<vector<int>> dp(n + 1, vector<int>(budget + 1, 0));

    // Fill DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= budget; ++j) {
            dp[i][j] = dp[i - 1][j]; // Option to not use this machine
            for (int s = 0; s * machines[i - 1].a <= j; ++s) {
                int t = (j - s * machines[i - 1].a) / machines[i - 1].b;
                dp[i][j] = max(dp[i][j], dp[i - 1][j - s * machines[i - 1].a - t * machines[i - 1].b] + s * machines[i - 1].p + t * machines[i - 1].q);
            }
        }
    }

    // Find the maximum production capacity within the budget
    for (int i = budget; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            if (dp[j][i] == dp[n][budget]) {
                return i / machines[j].a / machines[j].b;
            }
        }
    }
    return 0;
}

int main() {
    int N, X;
    cin >> N >> X;

    vector<Machine> machines(N);
    for (int i = 0; i < N; ++i) {
        cin >> machines[i].a >> machines[i].p >> machines[i].b >> machines[i].q;
    }

    cout << maxProductionCapacity(machines, X) << endl;

    return 0;
}