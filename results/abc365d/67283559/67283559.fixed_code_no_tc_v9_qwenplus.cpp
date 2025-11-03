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
    
    // Try both possible starting hands
    int maxScore = 0;
    
    for (int startIdx = 0; startIdx < 3; startIdx++) {
        vector<char> currentHand = hand;
        int score = 0;
        
        for (int i = 0; i < N; i++) {
            char opponentMove = S[i];
            char winningMove = getWinner(opponentMove);
            char losingMove = getLoser(opponentMove);
            
            bool canWin = false;
            for (char c : currentHand) {
                if (c == winningMove) {
                    canWin = true;
                    break;
                }
            }
            
            if (canWin) {
                score++;
                // Remove the winning move from hand
                vector<char> newHand;
                for (char c : currentHand) {
                    if (c != winningMove) {
                        newHand.push_back(c);
                    }
                }
                currentHand = newHand;
            } else {
                // Play any move (prefer to keep winning options for future)
                // Just remove one move that's not beneficial
                vector<char> newHand;
                bool removed = false;
                for (char c : currentHand) {
                    if (!removed && c != losingMove) {  // remove something that can't beat future R/P/S ideally
                        removed = true;
                        continue;
                    }
                    newHand.push_back(c);
                }
                if (!removed) {
                    // If we didn't remove anything, remove first
                    newHand.clear();
                    for (int j = 1; j < currentHand.size(); j++) {
                        newHand.push_back(currentHand[j]);
                    }
                }
                currentHand = newHand;
            }
        }
        maxScore = max(maxScore, score);
    }
    
    cout << maxScore << endl;
    return 0;
}