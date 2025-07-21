#include <bits/stdc++.h>
using namespace std;

int playGame(string S, vector<char> hand) {
    vector<char> next = hand;
    int total = 0;
    
    for (char c : S) {
        bool won = false;
        char used;
        
        // Try each available move to win
        for (char move : next) {
            if ((move == 'R' && c == 'S') || 
                (move == 'P' && c == 'R') || 
                (move == 'S' && c == 'P')) {
                total++;
                used = move;
                won = true;
                break;
            }
        }
        
        // If can't win, use opponent's move (will lose or draw)
        if (!won) {
            used = c;
        }
        
        // Update available moves for next round
        vector<char> newNext;
        for (char move : hand) {
            if (move != used) {
                newNext.push_back(move);
            }
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
    
    // First scenario: play optimally from beginning
    int res1 = playGame(S, hand);
    
    // Second scenario: skip first move
    if (N == 0) {
        cout << 0;
        return 0;
    }
    
    vector<char> next;
    for (char move : hand) {
        if (move != S[0]) {
            next.push_back(move);
        }
    }
    
    // Create substring excluding first character
    string subS = S.substr(1);
    vector<char> newHand = next;
    int res2 = playGame(subS, newHand);
    
    // Output the maximum of both strategies
    cout << max(res1, res2);
    return 0;
}