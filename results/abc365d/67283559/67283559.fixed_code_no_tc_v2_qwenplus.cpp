#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    vector<char> choices = {'R', 'P', 'S'};
    auto getWinningMove = [](char opponent) -> char {
        if (opponent == 'R') return 'P';
        if (opponent == 'P') return 'S';
        return 'R';
    };
    
    auto getNextAvailable = [](vector<char> current, char used) -> vector<char> {
        vector<char> result;
        for (char c : current) {
            if (c != used) {
                result.push_back(c);
            }
        }
        return result;
    };
    
    // Try all possible starting moves and find the maximum score
    int maxScore = 0;
    
    for (char firstMove : choices) {
        int score = 0;
        vector<char> available = choices;
        
        for (int i = 0; i < N; i++) {
            // Check if we can win
            bool canWin = false;
            char moveToUse = firstMove; // For first iteration, use the chosen first move
            
            if (i > 0) {
                // Find a winning move from available options if possible
                for (char move : available) {
                    if ((move == 'R' && S[i] == 'S') ||
                        (move == 'P' && S[i] == 'R') ||
                        (move == 'S' && S[i] == 'P')) {
                        moveToUse = move;
                        canWin = true;
                        break;
                    }
                }
                
                if (!canWin) {
                    // If we can't win, use any available move (tie or lose)
                    moveToUse = available[0];
                }
            }
            
            // Update score if we won
            if ((moveToUse == 'R' && S[i] == 'S') ||
                (moveToUse == 'P' && S[i] == 'R') ||
                (moveToUse == 'S' && S[i] == 'P')) {
                score++;
            }
            
            // Update available moves for next round
            available = getNextAvailable(choices, moveToUse);
        }
        
        maxScore = max(maxScore, score);
    }
    
    cout << maxScore << endl;
    return 0;
}