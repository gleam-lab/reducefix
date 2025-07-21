#include <bits/stdc++.h>
using namespace std;

int simulate(const string& S, const vector<char>& hand, char first_move) {
    int total = 0;
    vector<char> next = hand;
    char use = first_move;
    
    // Remove the first move from available moves for next round
    next.clear();
    for (auto d : hand) {
        if (d != use) next.push_back(d);
    }

    for (size_t i = 1; i < S.size(); ++i) {
        int score = 0;
        char best_move = ' ';
        for (char n : next) {
            if ((n == 'R' && S[i] == 'S') ||
                (n == 'P' && S[i] == 'R') ||
                (n == 'S' && S[i] == 'P')) {
                best_move = n;
                score = 1;
                break;
            }
        }
        total += score;
        
        // Update available moves for next round
        vector<char> new_next;
        for (char d : hand) {
            if (d != best_move) new_next.push_back(d);
        }
        next = new_next;
    }
    
    return total;
}

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    vector<char> hand = {'R', 'P', 'S'};
    
    // Try each possible first move and pick the one that gives maximum score
    int max_score = 0;
    for (char first_move : hand) {
        int score = simulate(S, hand, first_move);
        max_score = max(max_score, score);
    }
    
    cout << max_score;
    return 0;
}