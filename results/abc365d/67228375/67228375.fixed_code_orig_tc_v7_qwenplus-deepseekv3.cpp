#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(3, 0));
    
    // Initialize the first move
    char first_move = s[0];
    if (beats[first_move] == 'R') {
        dp[0][0] = 1; // R beats S
    }
    if (beats[first_move] == 'P') {
        dp[0][1] = 1; // P beats R
    }
    if (beats[first_move] == 'S') {
        dp[0][2] = 1; // S beats P
    }

    for (int i = 1; i < n; ++i) {
        char current = s[i];
        char winning_move = beats[current];
        
        // Previous moves could be R, P, or S
        for (int prev_move = 0; prev_move < 3; ++prev_move) {
            for (int current_move = 0; current_move < 3; ++current_move) {
                char move_char;
                if (current_move == 0) move_char = 'R';
                else if (current_move == 1) move_char = 'P';
                else move_char = 'S';

                if (move_char == winning_move) {
                    int new_score = dp[i-1][prev_move] + 1;
                    if (new_score > dp[i][current_move]) {
                        dp[i][current_move] = new_score;
                    }
                } else {
                    if (dp[i-1][prev_move] > dp[i][current_move]) {
                        dp[i][current_move] = dp[i-1][prev_move];
                    }
                }
            }
        }
    }

    int max_wins = max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    cout << max_wins << endl;

    return 0;
}