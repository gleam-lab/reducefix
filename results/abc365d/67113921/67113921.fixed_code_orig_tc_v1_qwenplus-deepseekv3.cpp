#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;

    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int>> dp(N, vector<int>(3, 0));

    char first_move = S[0];
    if (first_move == 'R') {
        dp[0][1] = 1; // P beats R
    } else if (first_move == 'P') {
        dp[0][2] = 1; // S beats P
    } else if (first_move == 'S') {
        dp[0][0] = 1; // R beats S
    }

    for (int i = 1; i < N; ++i) {
        char current = S[i];
        int beat_r = (current == 'S') ? 1 : 0;
        int beat_p = (current == 'R') ? 1 : 0;
        int beat_s = (current == 'P') ? 1 : 0;

        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + beat_r;
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + beat_p;
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + beat_s;
    }

    cout << max({dp[N-1][0], dp[N-1][1], dp[N-1][2]}) << endl;

    return 0;
}