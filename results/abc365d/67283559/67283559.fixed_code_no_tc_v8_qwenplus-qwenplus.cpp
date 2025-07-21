#include <bits/stdc++.h>
using namespace std;

int playGame(const string& S, const vector<char>& hand, int N) {
    vector<char> next = hand;
    int total = 0;
    
    for (int i = 0; i < N; ++i) {
        bool won = false;
        for (auto c : next) {
            if ((c == 'R' && S[i] == 'S') || 
                (c == 'P' && S[i] == 'R') || 
                (c == 'S' && S[i] == 'P')) {
                total++;
                next.clear();
                for (auto d : hand) {
                    if (d != c) next.push_back(d);
                }
                won = true;
                break;
            }
        }
        if (!won) {
            char use = S[i]; // Draw or loss, just use the same as opponent
            next.clear();
            for (auto d : hand) {
                if (d != use) next.push_back(d);
            }
        }
    }
    return total;
}

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    vector<char> hand = {'R', 'P', 'S'};
    
    // Case 1: Play normally from first round
    int score1 = playGame(S, hand, N);
    
    // Case 2: Skip first move and start from second move
    int score2 = 0;
    if (N > 1) {
        // Find best move for first round that wasn't used
        char firstMove = S[0];
        vector<char> remaining;
        for (auto c : hand) {
            if (c != firstMove) remaining.push_back(c);
        }
        score2 = playGame(S.substr(1), remaining, N - 1);
    }
    
    cout << max(score1, score2) << endl;
    return 0;
}