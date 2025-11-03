#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    // Rock beats Scissors, Paper beats Rock, Scissors beats Paper
    auto wins = [](char a, char b) {
        return (a == 'R' && b == 'S') || 
               (a == 'P' && b == 'R') || 
               (a == 'S' && b == 'P');
    };

    // Try both possible starting hands: one that beats first move, and one that doesn't
    vector<char> options = {'R', 'P', 'S'};
    
    int max_score = 0;
    
    // Try each possible initial hand choice
    for (char first_hand : options) {
        int score = 0;
        char current_hand = first_hand;
        
        for (int i = 0; i < N; i++) {
            if (wins(current_hand, S[i])) {
                score++;
            }
            // Update hand for next round: choose any move except the current one
            // We want to maximize future opportunities, so we pick optimally
            vector<char> available;
            for (char c : options) {
                if (c != current_hand) {
                    available.push_back(c);
                }
            }
            
            // Choose the best next hand among available options
            char best_next = available[0];
            int best_future_wins = 0;
            
            for (char next_hand : available) {
                int future_wins = 0;
                // Look ahead to see how many wins this choice might enable
                // In practice, we just need to avoid cycles and maintain flexibility
                // The key insight is that we should choose based on what beats the opponent's next move
                if (i + 1 < N && wins(next_hand, S[i+1])) {
                    future_wins = 1;
                }
                if (future_wins > best_future_wins) {
                    best_future_wins = future_wins;
                    best_next = next_hand;
                }
            }
            
            current_hand = best_next;
        }
        
        max_score = max(max_score, score);
    }
    
    // Alternative approach: greedy with state tracking
    // We realize that at each step we have two choices, and we want to maximize total wins
    // Use dynamic programming with state representing current hand
    
    vector<int> dp(3); // dp[0]=R, dp[1]=P, dp[2]=S
    vector<int> new_dp(3);
    vector<char> hands = {'R', 'P', 'S'};
    
    // Initialize: we can start with any hand
    fill(dp.begin(), dp.end(), 0);
    
    for (int i = 0; i < N; i++) {
        fill(new_dp.begin(), new_dp.end(), 0);
        
        for (int j = 0; j < 3; j++) {
            if (dp[j] == -1) continue;
            
            // From current hand j, try both possible next hands (can't repeat)
            for (int k = 0; k < 3; k++) {
                if (k == j) continue; // Can't use same hand twice
                
                int additional = 0;
                if (wins(hands[k], S[i])) {
                    additional = 1;
                }
                
                new_dp[k] = max(new_dp[k], dp[j] + additional);
            }
        }
        
        dp = new_dp;
    }
    
    max_score = max(max_score, *max_element(dp.begin(), dp.end()));
    
    cout << max_score << endl;
    
    return 0;
}