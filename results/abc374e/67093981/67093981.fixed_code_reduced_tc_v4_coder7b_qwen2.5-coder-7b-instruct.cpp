#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Process {
    int a, p, b, q;
};

int main() {
    int N, X;
    cin >> N >> X;

    vector<Process> processes(N);
    for (int i = 0; i < N; ++i) {
        cin >> processes[i].a >> processes[i].p >> processes[i].b >> processes[i].q;
        if (processes[i].a * processes[i].q > processes[i].b * processes[i].p) {
            swap(processes[i].a, processes[i].b);
            swap(processes[i].p, processes[i].q);
        }
    }

    vector<vector<long long>> dp(N + 1, vector<long long>(X + 1, LLONG_MAX));
    dp[0][0] = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= X; ++j) {
            dp[i][j] = dp[i - 1][j];
            for (int k = 0; k * processes[i - 1].a <= j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - k * processes[i - 1].a] + k * processes[i - 1].p);
            }
        }
    }

    int max_capacity = 0;
    for (int i = 0; i <= X; ++i) {
        int capacity = INT_MAX;
        for (const auto& proc : processes) {
            capacity = min(capacity, i / (proc.a * proc.b));
        }
        if (dp[N][i] != LLONG_MAX) {
            max_capacity = max(max_capacity, capacity);
        }
    }

    cout << max_capacity << endl;
    return 0;
}