#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int A, P, B, Q;
};

// Function to calculate the minimum production capacity for a given number of units
long long minProductionCapacity(const vector<Process>& processes, int units) {
    int N = processes.size();
    vector<vector<long long>> dp(N + 1, vector<long long>(units + 1, LLONG_MAX));
    dp[0][0] = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= units; ++j) {
            // Option 1: Don't use this process at all
            dp[i][j] = dp[i - 1][j];
            
            // Option 2: Use one unit of machine S_i
            if (j >= processes[i - 1].A) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - processes[i - 1].A] + processes[i - 1].P);
            }
            
            // Option 3: Use one unit of machine T_i
            if (j >= processes[i - 1].B) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - processes[i - 1].B] + processes[i - 1].Q);
            }
        }
    }

    return dp[N][units];
}

int main() {
    int N, X;
    cin >> N >> X;

    vector<Process> processes(N);
    for (int i = 0; i < N; ++i) {
        cin >> processes[i].A >> processes[i].P >> processes[i].B >> processes[i].Q;
    }

    int left = 0, right = X / processes.front().A; // Upper bound based on the first process's machine S_i
    while (left < right) {
        int mid = (left + right + 1) / 2;
        if (minProductionCapacity(processes, mid) > X) {
            right = mid - 1;
        } else {
            left = mid;
        }
    }

    cout << left << endl;
    return 0;
}