#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Machine {
    int a, p, b, q;
};

int main() {
    int N, X;
    cin >> N >> X;

    vector<Machine> machines(N);
    for (int i = 0; i < N; ++i) {
        cin >> machines[i].a >> machines[i].p >> machines[i].b >> machines[i].q;
    }

    // Initialize dp array with infinity
    vector<vector<long long>> dp(N + 1, vector<long long>(X + 1, LLONG_MAX));
    dp[0][0] = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= X; ++j) {
            for (int k = 0; k * machines[i - 1].a <= j; ++k) {
                int remaining_products = j - k * machines[i - 1].a;
                dp[i][j] = min(dp[i][j], dp[i - 1][remaining_products] + k * machines[i - 1].p);
                if (remaining_products >= machines[i - 1].b) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][remaining_products - machines[i - 1].b] + k * machines[i - 1].p + machines[i - 1].q);
                }
            }
        }
    }

    // Find the maximum production capacity
    int max_capacity = 0;
    for (int j = 0; j <= X; ++j) {
        if (dp[N][j] != LLONG_MAX) {
            max_capacity = j;
        } else {
            break;
        }
    }

    cout << max_capacity << endl;

    return 0;
}