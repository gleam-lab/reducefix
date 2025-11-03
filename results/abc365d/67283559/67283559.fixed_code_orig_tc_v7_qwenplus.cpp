#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    // Define the winning moves
    auto wins = [](char move) {
        if (move == 'R') return 'P';
        if (move == 'P') return 'S';
        return 'R'; // 'S' -> 'R'
    };
    
    // Try both possible starting hands: R, P, or S
    vector<char> options = {'R', 'P', 'S'};
    int max_score = 0;
    
    for (char first_hand : options) {
        int score = 0;
        char current_hand = first_hand;
        
        for (int i = 0; i < N; i++) {
            // If current hand beats opponent's move, we win
            if ((current_hand == 'R' && S[i] == 'S') ||
                (current_hand == 'P' && S[i] == 'R') ||
                (current_hand == 'S' && S[i] == 'P')) {
                score++;
            }
            // Update hand for next round: cannot reuse current hand
            // So choose among the other two, optimally
            vector<char> available;
            for (char c : options) {
                if (c != current_hand) {
                    available.push_back(c);
                }
            }
            
            // Choose the best available hand for next round
            // Prefer the one that can beat next opponent's move (if exists)
            if (i + 1 < N) {
                char desired = wins(S[i+1]);
                if (desired == available[0]) {
                    current_hand = available[0];
                } else if (available.size() > 1 && desired == available[1]) {
                    current_hand = available[1];
                } else {
                    // Otherwise pick the first available
                    current_hand = available[0];
                }
            }
        }
        max_score = max(max_score, score);
    }
    
    cout << max_score << endl;
    return 0;
}