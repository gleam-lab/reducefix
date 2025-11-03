#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<char> hand = {'R', 'P', 'S'};
    auto getWinner = [](char move) {
        if (move == 'R') return 'P';
        if (move == 'P') return 'S';
        return 'R';
    };

    int maxScore = 0;

    // Try all possible starting moves
    for (char firstMove : hand) {
        vector<char> available = hand;
        // Remove the first move from available
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
            
            // Update available moves: remove the one we just used
            available.clear();
            for (char h : hand) {
                if (h != currentMove) {
                    available.push_back(h);
                }
            }
            
            // Choose next move: prefer winning move if possible, otherwise any move
            char bestNext = available[0];
            char winningMove = getWinner(S[i]);
            
            // Look for the winning move in available options
            bool foundWinning = false;
            for (char a : available) {
                if (a == winningMove) {
                    bestNext = a;
                    foundWinning = true;
                    break;
                }
            }
            
            currentMove = bestNext;
        }
        
        maxScore = max(maxScore, score);
    }

    cout << maxScore << endl;
    return 0;
}