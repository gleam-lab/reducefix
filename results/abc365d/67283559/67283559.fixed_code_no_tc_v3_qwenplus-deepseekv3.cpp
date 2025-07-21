#include <bits/stdc++.h>
using namespace std;

int calculateMaxScore(const string& S) {
    int N = S.size();
    if (N == 0) return 0;
    
    // We can choose any initial move, so we try all possibilities
    int max_score = 0;
    const vector<char> possible_moves = {'R', 'P', 'S'};
    
    for (char initial_move : possible_moves) {
        int score = 0;
        char prev_move = initial_move;
        
        // Check if first move wins
        if ((prev_move == 'R' && S[0] == 'S') ||
            (prev_move == 'P' && S[0] == 'R') ||
            (prev_move == 'S' && S[0] == 'P')) {
            score++;
        }
        
        for (int i = 1; i < N; i++) {
            // The next move can't be the same as previous
            char current_move;
            if (prev_move != 'R' && ((S[i] == 'S' && 'R' != prev_move) || 
                                    (S[i] == 'P' && 'S' != prev_move) || 
                                    (S[i] == 'R' && 'P' != prev_move))) {
                // Choose the winning move if possible and different from previous
                if (S[i] == 'S') current_move = 'R';
                else if (S[i] == 'R') current_move = 'P';
                else current_move = 'S';
            } else if (prev_move != 'P' && ((S[i] == 'S' && 'R' != prev_move) || 
                                          (S[i] == 'P' && 'S' != prev_move) || 
                                          (S[i] == 'R' && 'P' != prev_move))) {
                if (S[i] == 'S') current_move = 'R';
                else if (S[i] == 'R') current_move = 'P';
                else current_move = 'S';
            } else if (prev_move != 'S' && ((S[i] == 'S' && 'R' != prev_move) || 
                                          (S[i] == 'P' && 'S' != prev_move) || 
                                          (S[i] == 'R' && 'P' != prev_move))) {
                if (S[i] == 'S') current_move = 'R';
                else if (S[i] == 'R') current_move = 'P';
                else current_move = 'S';
            } else {
                // If we can't win, choose a move that doesn't lose (same as opponent)
                current_move = S[i];
            }
            
            // Check if current move wins
            if ((current_move == 'R' && S[i] == 'S') ||
                (current_move == 'P' && S[i] == 'R') ||
                (current_move == 'S' && S[i] == 'P')) {
                score++;
            }
            prev_move = current_move;
        }
        
        max_score = max(max_score, score);
    }
    
    return max_score;
}

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    cout << calculateMaxScore(S) << endl;
    return 0;
}