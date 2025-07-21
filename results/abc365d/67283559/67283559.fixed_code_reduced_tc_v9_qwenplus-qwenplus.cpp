#include <bits/stdc++.h>
using namespace std;

int playGame(const string& S, const vector<char>& hand, char firstMove) {
    int N = S.size();
    vector<char> next = {hand[0], hand[1], hand[2]};
    int total = 0;
    
    // Set the initial move
    char use = firstMove;
    total += ((use == 'R' && S[0] == 'S') || 
              (use == 'P' && S[0] == 'R') || 
              (use == 'S' && S[0] == 'P'));
    
    // Update available moves for next round
    next.clear();
    for (auto d : hand) {
        if (d != use) next.push_back(d);
    }
    
    for (int i = 1; i < N; i++) {
        int score = 0;
        char bestMove = 'X';
        
        // Try all possible moves
        for (char n : next) {
            if ((n == 'R' && S[i] == 'S') ||
                (n == 'P' && S[i] == 'R') ||
                (n == 'S' && S[i] == 'P')) {
                score = 1;
                bestMove = n;
                break;
            }
        }
        
        if (score == 0) {
            // No winning move, pick any move
            bestMove = next[0];
        }
        
        total += score;
        
        // Update available moves for next round
        vector<char> newNext;
        for (auto d : hand) {
            if (d != bestMove) newNext.push_back(d);
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
    
    // Calculate maximum points by trying both starting options
    int result1 = playGame(S, hand, S[0]); // Start with opponent's first move
    int result2 = 0;
    
    // Try to start with a winning move if possible
    if (S[0] == 'R') result2 = playGame(S, hand, 'P');
    else if (S[0] == 'P') result2 = playGame(S, hand, 'S');
    else if (S[0] == 'S') result2 = playGame(S, hand, 'R');
    
    cout << max(result1, result2) << endl;
    return 0;
}