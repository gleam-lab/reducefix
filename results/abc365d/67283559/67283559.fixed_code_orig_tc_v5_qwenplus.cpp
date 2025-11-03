#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;
    cin >> N >> S;

    // Rock beats Scissors, Paper beats Rock, Scissors beats Paper
    auto wins = [](char a, char b) {
        return (a == 'R' && b == 'S') || 
               (a == 'P' && b == 'R') || 
               (a == 'S' && b == 'P');
    };

    // Try all 6 possible initial strategies: each of the 3 choices, and for each,
    // we can have two different orders of removing hands (but actually order doesn't matter)
    // We only need to try starting with each of the three moves
    vector<char> choices = {'R', 'P', 'S'};
    int max_score = 0;

    for (char first_choice : choices) {
        vector<char> available = {'R', 'P', 'S'};
        available.erase(find(available.begin(), available.end(), first_choice), available.end());
        
        int score = 0;
        char current_choice = first_choice;

        for (int i = 0; i < N; i++) {
            // If our current choice beats opponent's move, we win
            if (wins(current_choice, S[i])) {
                score++;
            }
            // Otherwise, we don't win, but we still use the same strategy logic

            // Update available moves: remove the one we just used
            // But we need to pick our next move from remaining options
            // If opponent's move is in our available moves, we must switch to it
            // Otherwise, we can keep our current choice
            
            vector<char> next_available;
            for (char c : {'R', 'P', 'S'}) {
                if (c != current_choice) {
                    next_available.push_back(c);
                }
            }

            // Choose the best move from available ones for next round
            char next_move = current_choice; // default: stay with current if possible
            bool found_better = false;
            
            for (char c : next_available) {
                if (wins(c, S[i])) {
                    next_move = c;
                    found_better = true;
                    break;
                }
            }
            
            // If we didn't find a winning move, choose any (we pick the first)
            if (!found_better && !next_available.empty()) {
                next_move = next_available[0];
            }
            
            current_choice = next_move;
        }
        
        max_score = max(max_score, score);
    }

    cout << max_score << endl;
    return 0;
}