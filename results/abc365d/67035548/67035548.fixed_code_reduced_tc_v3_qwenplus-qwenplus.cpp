#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Returns 1 if a beats b, -1 if b beats a, 0 if tie
int cmp(char a, char b) {
    if (a == 'P') {
        if (b == 'P') return 0;
        if (b == 'R') return 1;
        if (b == 'S') return -1;
    }
    if (a == 'R') {
        if (b == 'P') return -1;
        if (b == 'R') return 0;
        if (b == 'S') return 1;
    }
    if (a == 'S') {
        if (b == 'P') return 1;
        if (b == 'R') return -1;
        if (b == 'S') return 0;
    }
    return 0; // Should not reach here
}

char winning_move(char c) {
    if (c == 'R') return 'P';
    if (c == 'P') return 'S';
    if (c == 'S') return 'R';
    return c; // Should not reach here
}

int solve(const string& s) {
    int n = s.size();
    vector<int> dp(n + 1, 0);
    char last_move = 'X'; // No move used yet
    
    int max_wins = 0;
    int current_wins = 0;
    
    // Forward pass
    for (int i = 0; i < n; ++i) {
        char opponent = s[i];
        char move = winning_move(opponent);
        
        if (move != last_move) {
            current_wins++;
            last_move = move;
        } else {
            // If we can't use the winning move due to restriction,
            // try to find an alternative that still wins or ties
            // but this would be complex, so better to apply dynamic programming
            
            // For now, reset the sequence and start fresh
            int alt_count = 0;
            char curr_move = 'X';
            
            for (int j = i; j < n; ++j) {
                char alt_opponent = s[j];
                char alt_move = winning_move(alt_opponent);
                
                if (alt_move != curr_move) {
                    alt_count++;
                    curr_move = alt_move;
                }
            }
            
            current_wins = max(current_wins, alt_count);
            break; // Since we reset, no need to continue forward pass
        }
    }
    
    max_wins = current_wins;
    current_wins = 0;
    last_move = 'X';
    
    // Backward pass
    for (int i = n - 1; i >= 0; --i) {
        char opponent = s[i];
        char move = winning_move(opponent);
        
        if (move != last_move) {
            current_wins++;
            last_move = move;
        } else {
            int alt_count = 0;
            char curr_move = 'X';
            
            for (int j = i; j >= 0; --j) {
                char alt_opponent = s[j];
                char alt_move = winning_move(alt_opponent);
                
                if (alt_move != curr_move) {
                    alt_count++;
                    curr_move = alt_move;
                }
            }
            
            current_wins = max(current_wins, alt_count);
            break;
        }
    }
    
    max_wins = max(max_wins, current_wins);
    return max_wins;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    cout << solve(s) << endl;
    
    return 0;
}