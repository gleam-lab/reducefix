#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Process {
    int a, p, b, q;
};

// Function to calculate the maximum production capacity for a given budget
int maxProductionCapacity(int n, vector<Process>& processes, int budget) {
    vector<vector<int>> dp(n + 1, vector<int>(budget + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= budget; ++j) {
            dp[i][j] = dp[i - 1][j]; // Option 1: Don't buy any machine for this process
            if (j >= processes[i - 1].p) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - processes[i - 1].p] + processes[i - 1].a); // Buy machine S_i
            }
            if (j >= processes[i - 1].q) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - processes[i - 1].q] + processes[i - 1].b); // Buy machine T_i
            }
        }
    }

    // Find the maximum production capacity
    int max_capacity = 0;
    for (int j = 0; j <= budget; ++j) {
        max_capacity = max(max_capacity, dp[n][j]);
    }

    return max_capacity;
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<Process> processes(n);
    for (int i = 0; i < n; ++i) {
        cin >> processes[i].a >> processes[i].p >> processes[i].b >> processes[i].q;
    }

    // Calculate the maximum production capacity within the given budget
    int result = maxProductionCapacity(n, processes, x);
    cout << result << endl;

    return 0;
}