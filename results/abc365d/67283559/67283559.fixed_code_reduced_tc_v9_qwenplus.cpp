#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    vector<char> hand = {'R', 'P', 'S'};
    auto getWinner = [](char a, char b) {
        if ((a == 'R' && b == 'S') || (a == 'P' && b == 'R') || (a == 'S' && b == 'P'))
            return 1;
        else if (a == b)
            return 0;
        else
            return -1;
    };
    
    int maxScore = 0;
    
    // Try all possible starting hands (3 choices)
    for (char firstMove : hand) {
        vector<char> currentHand = hand;
        int score = 0;
        
        for (int i = 0; i < N; i++) {
            // Find a move in current hand that beats S[i]
            char bestMove = '\0';
            for (char move : currentHand) {
                if (getWinner(move, S[i]) == 1) {
                    bestMove = move;
                    break;
                }
            }
            
            // If no winning move, choose any (preferably one that ties or loses less badly)
            if (bestMove == '\0') {
                // Try to find a tie
                bool foundTie = false;
                for (char move : currentHand) {
                    if (move == S[i]) {
                        bestMove = move;
                        foundTie = true;
                        break;
                    }
                }
                // Otherwise pick the first available
                if (!foundTie) {
                    bestMove = currentHand[0];
                }
            }
            
            score += (getWinner(bestMove, S[i]) == 1);
            
            // Update hand: remove the used move
            vector<char> newHand;
            for (char move : currentHand) {
                if (move != bestMove) {
                    newHand.push_back(move);
                }
            }
            currentHand = newHand;
        }
        
        maxScore = max(maxScore, score);
    }
    
    cout << maxScore << endl;
    return 0;
}