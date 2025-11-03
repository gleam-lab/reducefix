#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<char> hand = {'R', 'P', 'S'};
    
    // Try all 3 possible starting moves
    int max_score = 0;
    
    for (char first_move : hand) {
        vector<char> available = hand;
        // Remove the first move from available
        available.erase(remove(available.begin(), available.end(), first_move), available.end());
        
        int score = 0;
        char current_move = first_move;
        
        for (int i = 0; i < N; i++) {
            // Check if current move beats opponent's move
            if ((current_move == 'R' && S[i] == 'S') ||
                (current_move == 'P' && S[i] == 'R') ||
                (current_move == 'S' && S[i] == 'P')) {
                score++;
            }
            
            // For next round, eliminate the current move from options
            if (i < N - 1) {
                // Update available moves for next round
                vector<char> next_available;
                for (char c : hand) {
                    if (c != current_move) {
                        next_available.push_back(c);
                    }
                }
                available = next_available;
                
                // Choose the best move from remaining options for next round
                current_move = available[0]; // We'll check which one is best
                bool found_winning = false;
                
                for (char move : available) {
                    if ((move == 'R' && S[i+1] == 'S') ||
                        (move == 'P' && S[i+1] == 'R') ||
                        (move == 'S' && S[i+1] == 'P')) {
                        current_move = move;
                        found_winning = true;
                        break;
                    }
                }
                
                // If no winning move, pick any (we already have current_move set)
                if (!found_winning && !available.empty()) {
                    current_move = available[0];
                }
            }
        }
        
        max_score = max(max_score, score);
    }
    
    cout << max_score << endl;
    return 0;
}