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
    
    int maxScore = 0;
    
    // Try each possible starting move
    for (char firstMove : hand) {
        vector<char> available = hand;
        // Remove the first move from available options
        available.erase(remove(available.begin(), available.end(), firstMove), available.end());
        
        int score = 0;
        char currentMove = firstMove;
        
        for (int i = 0; i < N; i++) {
            // Check if current move beats opponent's move
            if ((currentMove == 'R' && S[i] == 'S') ||
                (currentMove == 'P' && S[i] == 'R') ||
                (currentMove == 'S' && S[i] == 'P')) {
                score++;
            }
            
            // If not last round, choose next move from remaining options
            if (i < N - 1) {
                // Choose the best move from remaining options
                char bestMove = available[0];
                bool foundWinning = false;
                
                for (char move : available) {
                    if ((move == 'R' && S[i+1] == 'S') ||
                        (move == 'P' && S[i+1] == 'R') ||
                        (move == 'S' && S[i+1] == 'P')) {
                        bestMove = move;
                        foundWinning = true;
                        break;
                    }
                }
                
                if (!foundWinning) {
                    bestMove = available[0]; // Just pick first available
                }
                
                currentMove = bestMove;
                
                // Update available moves (remove the one we just used)
                vector<char> newAvailable;
                for (char move : available) {
                    if (move != currentMove) {
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