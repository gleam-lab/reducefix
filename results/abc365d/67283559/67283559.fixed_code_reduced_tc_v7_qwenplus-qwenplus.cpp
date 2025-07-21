#include <bits/stdc++.h>
using namespace std;

int solve(const string& S, const vector<char>& hand, char first_move) {
    int n = S.size();
    vector<char> next;
    for (auto c : hand) {
        if (c != first_move) next.push_back(c);
    }
    
    int total = 0;
    for (int i = 1; i < n; ++i) {
        int score = 0;
        char use = 'X'; // placeholder
        
        for (auto c : next) {
            if ((c == 'R' && S[i] == 'S') || 
                (c == 'P' && S[i] == 'R') || 
                (c == 'S' && S[i] == 'P')) {
                score = 1;
                use = c;
                break;
            }
        }
        
        if (use == 'X') use = S[i]; // if no winning move found
        
        total += score;
        
        vector<char> new_next;
        for (auto c : hand) {
            if (c != use) new_next.push_back(c);
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
    
    // Try all possible first moves
    int max_score = 0;
    for (auto first_move : hand) {
        int score = 0;
        // Check if the first move wins
        if ((first_move == 'R' && S[0] == 'S') ||
            (first_move == 'P' && S[0] == 'R') ||
            (first_move == 'S' && S[0] == 'P')) {
            score = 1;
        }
        
        // Compute the rest of the game
        score += solve(S, hand, first_move);
        max_score = max(max_score, score);
    }
    
    cout << max_score << endl;
    return 0;
}