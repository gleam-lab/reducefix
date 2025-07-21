#include <bits/stdc++.h>
using namespace std;

int playGame(const string& S, const vector<char>& hand, int N, bool isFirstMoveFree) {
    vector<char> next = hand;
    int total = 0;

    for (int i = 0; i < N; i++) {
        int score = 0;
        char use = ' ';

        // Try each possible move
        for (char n : next) {
            if ((n == 'R' && S[i] == 'S') || 
                (n == 'P' && S[i] == 'R') || 
                (n == 'S' && S[i] == 'P')) {
                score = 1;
                use = n;
                break;
            }
        }

        // If no winning move was available
        if (score == 0) {
            // If first move is free (we can pick any move), choose the winning one
            if (isFirstMoveFree && i == 0) {
                if (S[i] == 'R') use = 'P';
                else if (S[i] == 'P') use = 'S';
                else use = 'R';
            } else {
                // Otherwise, just copy opponent's move
                use = S[i];
            }
        }

        total += score;
        
        // Update available moves for next round
        vector<char> newNext;
        for (char c : hand) {
            if (c != use) newNext.push_back(c);
        }
        next = newNext;
    }

    return total;
}

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<char> hand = {'R', 'P', 'S'};
    
    // Case 1: We choose the first move normally
    int score1 = playGame(S, hand, N, false);
    
    // Case 2: First move is free, we can beat opponent's first move
    int score2 = playGame(S, hand, N, true);

    cout << max(score1, score2) << endl;
    return 0;
}