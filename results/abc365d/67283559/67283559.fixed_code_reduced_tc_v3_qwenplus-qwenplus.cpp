#include <bits/stdc++.h>
using namespace std;

int simulate(const string& S, const vector<char>& hand, char first_move) {
    int n = S.size();
    vector<char> next = hand;
    int total = 0;
    
    char use = first_move;
    // Find the score for the first move
    if (use == 'R' && S[0] == 'S') total++;
    else if (use == 'P' && S[0] == 'R') total++;
    else if (use == 'S' && S[0] == 'P') total++;
    
    for (int i = 1; i < n; ++i) {
        vector<char> possible_moves;
        for (auto c : hand)
            if (c != use)
                possible_moves.push_back(c);
        next = possible_moves;
        
        int score = 0;
        for (auto c : next) {
            if (c == 'R' && S[i] == 'S') {
                use = c;
                score++;
                break;
            }
            if (c == 'P' && S[i] == 'R') {
                use = c;
                score++;
                break;
            }
            if (c == 'S' && S[i] == 'P') {
                use = c;
                score++;
                break;
            }
        }
        if (score == 0) {
            // If we can't win, pick any move different from previous
            use = next.empty() ? S[i] : next[0];
        }
        total += score;
    }
    return total;
}

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    vector<char> hand = {'R', 'P', 'S'};
    
    // Try all possible first moves and take maximum score
    int max_score = 0;
    for (auto move : hand) {
        if (move == S[0]) continue; // Can't use same move as opponent
        max_score = max(max_score, simulate(S, hand, move));
    }
    
    cout << max_score;
    return 0;
}