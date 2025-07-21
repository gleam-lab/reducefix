#include <bits/stdc++.h>
using namespace std;

int calculateScore(const string& S, char firstMove) {
    int score = 0;
    char currentMove = firstMove;
    unordered_set<char> banned;
    
    // First move
    if (currentMove == 'R' && S[0] == 'S') score++;
    else if (currentMove == 'P' && S[0] == 'R') score++;
    else if (currentMove == 'S' && S[0] == 'P') score++;
    
    banned.insert(currentMove);
    
    for (int i = 1; i < S.size(); ++i) {
        char bestMove = ' ';
        int bestScore = -1;
        
        // Try all possible moves not in banned
        for (char move : {'R', 'P', 'S'}) {
            if (banned.count(move)) continue;
            
            int currentScore = 0;
            if (move == 'R' && S[i] == 'S') currentScore = 1;
            else if (move == 'P' && S[i] == 'R') currentScore = 1;
            else if (move == 'S' && S[i] == 'P') currentScore = 1;
            
            if (currentScore > bestScore) {
                bestScore = currentScore;
                bestMove = move;
            }
        }
        
        if (bestMove == ' ') {
            // All moves are banned, choose the same as opponent (score 0)
            bestMove = S[i];
            bestScore = 0;
        }
        
        score += bestScore;
        banned.clear();
        banned.insert(bestMove);
    }
    
    return score;
}

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    int maxScore = 0;
    // Try all possible initial moves
    for (char initialMove : {'R', 'P', 'S'}) {
        int score = calculateScore(S, initialMove);
        if (score > maxScore) {
            maxScore = score;
        }
    }
    
    cout << maxScore;
    return 0;
}