#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    // Score mapping: what beats what
    auto wins = [](char a, char b) -> bool {
        return (a == 'R' && b == 'S') || 
               (a == 'P' && b == 'R') || 
               (a == 'S' && b == 'P');
    };
    
    // Try both possible starting choices for the first round
    vector<char> choices = {'R', 'P', 'S'};
    int max_score = 0;
    
    for (char first_choice : choices) {
        if (first_choice == S[0]) continue; // Can't use same as opponent in first round
        
        int score = 0;
        char current_choice = first_choice;
        
        for (int i = 0; i < N; i++) {
            // If we can win this round with current choice
            if (wins(current_choice, S[i])) {
                score++;
            }
            // Update our choice for next round - choose any move that isn't the current one
            // We want to maximize future options, so we pick a move that will be available
            // The key insight: we must avoid the opponent's move from this round
            // But also consider what we just played
            
            // For next round, we can choose any move except the one we just used
            // However, we need to make sure we can still play optimally
            // Let's try to maintain flexibility
            
            if (i == N-1) break; // No next round
            
            // Find next valid choice (not the current choice)
            // Prefer a choice that can beat the next opponent move if possible
            char best_next = 'X';
            int best_outcome = -1;
            
            for (char c : choices) {
                if (c == current_choice) continue; // Can't repeat same move
                
                int future_score = 0;
                if (wins(c, S[i+1])) future_score = 1;
                
                if (future_score > best_outcome) {
                    best_outcome = future_score;
                    best_next = c;
                }
            }
            
            current_choice = best_next;
        }
        
        max_score = max(max_score, score);
    }
    
    // Special case: if we can't make any initial choice (all would be same as opponent's first move)
    // Then we have to start by playing the same move, getting 0 points in first round
    if (max_score == 0) {
        // We'll have to use S[0] in first round, then choose between the other two
        vector<char> remaining;
        for (char c : choices) {
            if (c != S[0]) remaining.push_back(c);
        }
        
        // Try both possibilities for second move
        for (char second_choice : remaining) {
            int score = 0;
            char prev_choice = S[0]; // First move is same as opponent
            char current_choice = second_choice;
            
            // First round: same move, no point
            if (N > 1) {
                for (int i = 1; i < N; i++) {
                    if (wins(current_choice, S[i])) {
                        score++;
                    }
                    
                    if (i == N-1) break;
                    
                    // Choose next move (can't be same as current)
                    char next_choice = 'X';
                    for (char c : choices) {
                        if (c == current_choice) continue;
                        next_choice = c;
                        break;
                    }
                    
                    // Look ahead to see which choice is better
                    for (char c : choices) {
                        if (c == current_choice) continue;
                        if (wins(c, S[i+1])) {
                            next_choice = c;
                            break;
                        }
                    }
                    
                    prev_choice = current_choice;
                    current_choice = next_choice;
                }
            }
            
            max_score = max(max_score, score);
        }
    }
    
    cout << max_score << endl;
    return 0;
}