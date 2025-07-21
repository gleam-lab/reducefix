#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    // Define possible moves and initialize variables
    vector<char> hand = {'R', 'P', 'S'};
    int total = 0;
    
    // Iterate through each character in the string
    for (int i = 0; i < N; ++i) {
        int max_score = 0;
        char best_move = S[i];
        
        // Try each move to maximize the score
        for (char move : hand) {
            int score = 0;
            if ((move == 'R' && S[i] == 'S') || 
                (move == 'P' && S[i] == 'R') || 
                (move == 'S' && S[i] == 'P')) {
                score = 1;
            }
            if (score > max_score) {
                max_score = score;
                best_move = move;
            }
        }
        
        // Update total score and remove the chosen move from the options
        total += max_score;
        hand.erase(remove(hand.begin(), hand.end(), best_move), hand.end());
    }
    
    // Reset hand for the second part of the problem
    hand = {'R', 'P', 'S'};
    int total2 = 0;
    
    // Repeat the process for the first character of the string
    for (int i = 1; i < N; ++i) {
        int max_score = 0;
        char best_move = S[0];
        
        for (char move : hand) {
            int score = 0;
            if ((move == 'R' && S[i] == 'S') || 
                (move == 'P' && S[i] == 'R') || 
                (move == 'S' && S[i] == 'P')) {
                score = 1;
            }
            if (score > max_score) {
                max_score = score;
                best_move = move;
            }
        }
        
        total2 += max_score;
        hand.erase(remove(hand.begin(), hand.end(), best_move), hand.end());
    }
    
    // Output the maximum score between the two parts
    cout << max(total, total2);
}