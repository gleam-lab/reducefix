#include <bits/stdc++.h>
using namespace std;

int calculateMaxScore(const string& S) {
    int N = S.size();
    if (N == 0) return 0;
    
    int score = 0;
    vector<char> available = {'R', 'P', 'S'};
    char lastUsed = '\0';
    
    for (int i = 0; i < N; ++i) {
        char opponent = S[i];
        char bestMove = '\0';
        
        // Find the move that beats the opponent's move
        if (opponent == 'R') bestMove = 'P';
        else if (opponent == 'P') bestMove = 'S';
        else if (opponent == 'S') bestMove = 'R';
        
        // If the best move is available and not used last time, use it
        if (bestMove != '\0' && bestMove != lastUsed) {
            score++;
            lastUsed = bestMove;
        } else {
            // Otherwise, choose a move that doesn't lose (same as opponent's move)
            lastUsed = opponent;
        }
    }
    
    return score;
}

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    int maxScore = calculateMaxScore(S);
    cout << maxScore << endl;
    
    return 0;
}