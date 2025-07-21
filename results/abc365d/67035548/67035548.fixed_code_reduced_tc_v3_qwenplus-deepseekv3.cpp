#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // default case (shouldn't occur)
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    vector<vector<int>> dp(n, vector<int>(3, 0));
    // dp[i][0] = using 'R' at position i
    // dp[i][1] = using 'P' at position i
    // dp[i][2] = using 'S' at position i
    
    // Initialize the first move
    char first_move = s[0];
    dp[0][0] = (win('R') == first_move) ? 1 : 0; // 'R'
    dp[0][1] = (win('P') == first_move) ? 1 : 0; // 'P'
    dp[0][2] = (win('S') == first_move) ? 1 : 0; // 'S'
    
    for (int i = 1; i < n; ++i) {
        char current_move = s[i];
        int current_win_r = (win('R') == current_move) ? 1 : 0;
        int current_win_p = (win('P') == current_move) ? 1 : 0;
        int current_win_s = (win('S') == current_move) ? 1 : 0;
        
        // Transition from previous moves
        dp[i][0] = current_win_r + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = current_win_p + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = current_win_s + max(dp[i-1][0], dp[i-1][1]);
    }
    
    int max_wins = max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    cout << max_wins << endl;
    
    return 0;
}