#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    vector<char> choices = {'R', 'P', 'S'};
    int max_wins = 0;
    
    // Try all possible starting hands (R, P, S)
    for (char first_hand : choices) {
        vector<char> available = {'R', 'P', 'S'};
        int wins = 0;
        char current_hand = first_hand;
        
        for (int i = 0; i < N; i++) {
            // Play the current hand against opponent's move S[i]
            if ((current_hand == 'R' && S[i] == 'S') ||
                (current_hand == 'P' && S[i] == 'R') ||
                (current_hand == 'S' && S[i] == 'P')) {
                wins++;
            }
            
            // Update available moves for next round (remove current hand)
            vector<char> next_available;
            for (char c : available) {
                if (c != current_hand) {
                    next_available.push_back(c);
                }
            }
            available = next_available;
            
            // Choose best hand for next round if not last round
            if (i < N - 1 && !available.empty()) {
                // Choose the hand that can beat S[i+1] if possible
                char best_next = available[0];
                bool found_winner = false;
                
                for (char c : available) {
                    if ((c == 'R' && S[i+1] == 'S') ||
                        (c == 'P' && S[i+1] == 'R') ||
                        (c == 'S' && S[i+1] == 'P')) {
                        best_next = c;
                        found_winner = true;
                        break;
                    }
                }
                current_hand = best_next;
            }
        }
        
        max_wins = max(max_wins, wins);
    }
    
    cout << max_wins << endl;
    return 0;
}