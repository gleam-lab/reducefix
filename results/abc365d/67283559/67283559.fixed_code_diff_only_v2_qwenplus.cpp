#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    vector<char> hand = {'R', 'P', 'S'};
    auto getWinner = [](char move) -> char {
        if (move == 'R') return 'P';
        if (move == 'P') return 'S';
        return 'R';
    };
    
    auto getLoser = [](char move) -> char {
        if (move == 'R') return 'S';
        if (move == 'P') return 'R';
        return 'P';
    };
    
    // Try all three possible starting moves
    int maxScore = 0;
    
    for (char firstMove : hand) {
        vector<char> available = hand;
        int score = 0;
        
        for (int i = 0; i < N; i++) {
            // Find a winning move if possible
            char opponent = S[i];
            char winningMove = getWinner(opponent);
            bool canWin = false;
            
            for (char move : available) {
                if (move == winningMove) {
                    canWin = true;
                    break;
                }
            }
            
            if (canWin) {
                score++;
                // Remove the used move from available options
                vector<char> newAvailable;
                for (char move : available) {
                    if (move != winningMove) {
                        newAvailable.push_back(move);
                    }
                }
                available = newAvailable;
            } else {
                // Play any available move (doesn't win)
                char use = available[0];
                // Remove the used move
                vector<char> newAvailable;
                for (char move : available) {
                    if (move != use) {
                        newAvailable.push_back(move);
                    }
                }
                available = newAvailable;
            }
        }
        
        maxScore = max(maxScore, score);
    }
    
    cout << maxScore << endl;
    return 0;
}