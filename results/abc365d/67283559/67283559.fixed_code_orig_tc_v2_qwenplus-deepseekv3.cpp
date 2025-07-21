#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> score_map = {
    {'R', 1}, // beats Scissors
    {'P', 1}, // beats Rock
    {'S', 1}  // beats Paper
};

unordered_map<char, char> beats = {
    {'R', 'S'},
    {'P', 'R'},
    {'S', 'P'}
};

int max_score(int index, char last_move, const string &S, vector<vector<int>> &dp) {
    if (index == S.size()) {
        return 0;
    }
    if (dp[index][last_move] != -1) {
        return dp[index][last_move];
    }
    int max_val = 0;
    for (char move : {'R', 'P', 'S'}) {
        if (move != last_move) {
            int current = (beats[move] == S[index]) ? 1 : 0;
            current += max_score(index + 1, move, S, dp);
            if (current > max_val) {
                max_val = current;
            }
        }
    }
    dp[index][last_move] = max_val;
    return max_val;
}

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    // Initialize DP table. We use 4 states (0: no last move, 1: R, 2: P, 3: S)
    vector<vector<int>> dp(N + 1, vector<int>(4, -1));
    
    // Convert last_move to index: 0 (no move), 1 (R), 2 (P), 3 (S)
    auto char_to_index = [](char c) {
        if (c == 'R') return 1;
        if (c == 'P') return 2;
        if (c == 'S') return 3;
        return 0;
    };
    
    function<int(int, char)> memo = [&](int i, char last) {
        if (i == N) return 0;
        int idx = char_to_index(last);
        if (dp[i][idx] != -1) return dp[i][idx];
        int res = 0;
        for (char m : {'R', 'P', 'S'}) {
            if (m != last) {
                int gain = (beats[m] == S[i]) ? 1 : 0;
                res = max(res, gain + memo(i + 1, m));
            }
        }
        dp[i][idx] = res;
        return res;
    };
    
    int total = memo(0, '\0');
    cout << total << endl;
    return 0;
}