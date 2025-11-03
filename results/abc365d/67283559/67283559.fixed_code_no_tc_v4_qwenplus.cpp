#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    
    vector<char> options = {'R', 'P', 'S'};
    auto getWinner = [](char player, char opponent) -> int {
        if ((player == 'R' && opponent == 'S') ||
            (player == 'P' && opponent == 'R') ||
            (player == 'S' && opponent == 'P')) {
            return 1;
        }
        return 0;
    };
    
    int maxScore = 0;
    
    // Try each possible starting move
    for (char firstMove : options) {
        vector<char> available = options;
        // Remove the chosen move
        available.erase(remove(available.begin(), available.end(), firstMove), available.end());
        
        int score = 0;
        char currentMove = firstMove;
        
        for (int i = 0; i < N; i++) {
            // Add score for current move
            score += getWinner(currentMove, S[i]);
            
            // Update available moves for next round (remove current move)
            if (i < N - 1) {
                // For next round, we can't use the current move again
                // So our options are the other two moves
                vector<char> nextAvailable;
                for (char opt : options) {
                    if (opt != currentMove) {
                        nextAvailable.push_back(opt);
                    }
                }
                
                // Choose the best move from available options for next round
                char bestNext = nextAvailable[0];
                int bestScore = 0;
                
                for (char nextMove : nextAvailable) {
                    int futureScore = getWinner(nextMove, S[i + 1]);
                    if (futureScore > bestScore) {
                        bestScore = futureScore;
                        bestNext = nextMove;
                    }
                }
                
                currentMove = bestNext;
            }
        }
        
        maxScore = max(maxScore, score);
    }
    
    cout << maxScore << endl;
    return 0;
}