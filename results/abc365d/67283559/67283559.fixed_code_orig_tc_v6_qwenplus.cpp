#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
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

    vector<char> choices = {'R', 'P', 'S'};
    int max_score = 0;

    // Try all 3 possible starting choices
    for (char first_choice : choices) {
        vector<char> available = {'R', 'P', 'S'};
        // Remove the first choice
        available.erase(find(available.begin(), available.end(), first_choice));
        
        int score = 0;
        char last_used = first_choice;
        
        // First round
        if (wins(last_used, S[0])) {
            score++;
        }
        
        // Remaining rounds
        for (int i = 1; i < N; i++) {
            char best_move = ' ';
            bool can_win = false;
            
            // Try moves from remaining options
            for (char move : available) {
                if (wins(move, S[i])) {
                    best_move = move;
                    can_win = true;
                    break;
                }
            }
            
            // If we can't win, use the opponent's move (minimize information)
            if (!can_win) {
                best_move = S[i];
            }
            
            if (wins(best_move, S[i])) {
                score++;
            }
            
            // Update available moves - remove the one we just used
            last_used = best_move;
            available.clear();
            for (char c : choices) {
                if (c != last_used) {
                    available.push_back(c);
                }
            }
        }
        
        max_score = max(max_score, score);
    }

    cout << max_score << endl;
    
    return 0;
}