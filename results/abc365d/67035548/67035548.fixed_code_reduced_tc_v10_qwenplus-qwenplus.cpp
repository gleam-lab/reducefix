#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Returns the move that beats the given move
char winning_move(char c) {
    if (c == 'R') return 'P';
    if (c == 'P') return 'S';
    if (c == 'S') return 'R';
    return c; // For invalid inputs, just return same
}

int calculate_max_wins(const string& s) {
    int n = s.size();
    if (n == 0) return 0;
    
    // dp[i] = max wins from position i to end
    vector<int> dp(n + 2, 0);
    
    // Try all possible ending positions for the prefix
    for (int i = n - 1; i >= 0; i--) {
        // We can either start a new sequence at i or continue from i+1
        char last_move = winning_move(s[i]);
        
        // Option 1: Start new sequence at i
        int option1 = 1;
        char curr_move = last_move;
        
        // Extend as far as possible
        for (int j = i + 1; j < n; j++) {
            if (curr_move != winning_move(s[j])) {
                option1++;
                curr_move = winning_move(s[j]);
            } else {
                curr_move = s[j]; // Opponent plays same move
            }
        }
            
        // Option 2: Skip starting at i, use value from i+1
        int option2 = dp[i + 1];
        
        dp[i] = max(option1, option2);
    }
    
    return dp[0];
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    cout << calculate_max_wins(s) << endl;
    
    return 0;
}