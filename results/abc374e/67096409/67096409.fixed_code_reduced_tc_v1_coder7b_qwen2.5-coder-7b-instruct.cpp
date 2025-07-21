#include <iostream>
#include <vector>
#include <algorithm>

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
    }

    // Sort processes based on the ratio of cost per product
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return static_cast<double>(a.p) / a.a < static_cast<double>(b.p) / b.a;
    });

    vector<vector<long long>> dp(X + 1, vector<long long>(N + 1, 1e18));
    dp[0][0] = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= X; ++j) {
            dp[j][i] = dp[j][i - 1]; // Not using any machine for process i
            for (int k = 0; k * processes[i - 1].a <= j; ++k) {
                dp[j][i] = min(dp[j][i], dp[j - k * processes[i - 1].a][i - 1] + k * processes[i - 1].p);
            }
        }
    }

    int left = 0, right = X;
    while (left < right) {
        int mid = (left + right + 1) / 2;
        bool possible = true;
        for (int i = 0; i < N; ++i) {
            if (dp[mid][i + 1] > X) {
                possible = false;
                break;
            }
        }
        if (possible) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    cout << left << endl;
    return 0;
}