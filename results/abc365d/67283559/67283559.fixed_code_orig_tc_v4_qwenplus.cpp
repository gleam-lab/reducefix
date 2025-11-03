#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;
    cin >> N >> S;

    // Map for what beats what
    unordered_map<char, char> wins = {{'R','P'}, {'P','S'}, {'S','R'}};
    
    // Try all 3 possible starting moves
    vector<char> choices = {'R', 'P', 'S'};
    int max_score = 0;

    for (char first_move : choices) {
        int score = 0;
        char current_move = first_move;
        
        for (int i = 0; i < N; i++) {
            // If current move beats opponent's move, get a point
            if (wins[current_move] == S[i]) {
                score++;
            }
            // Update next move: choose any move that is not the current one
            // We can pick either of the two remaining moves arbitrarily since 
            // the choice only affects future rounds and we want to maximize overall score
            // So we'll use a deterministic strategy: cycle through options
            if (current_move == 'R') {
                current_move = (S[i] == 'R') ? 'P' : 'S';  // Prefer winning move if possible
            } else if (current_move == 'P') {
                current_move = (S[i] == 'P') ? 'S' : 'R';
            } else { // current_move == 'S'
                current_move = (S[i] == 'S') ? 'R' : 'P';
            }
        }
        
        max_score = max(max_score, score);
    }

    cout << max_score << endl;
    return 0;
}