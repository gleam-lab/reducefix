#include <bits/stdc++.h>
using namespace std;

int solve(string S, vector<char> hand) {
    int n = S.size();
    char last_use = '\0';
    int total = 0;
    
    // Initialize possible choices
    vector<char> next = hand;
    
    for(int i = 0; i < n; i++) {
        bool won = false;
        char use = S[i]; // default to same as opponent if we can't win
        
        // Try all possible moves to find a winning one
        for(auto c : next) {
            if((c == 'R' && S[i] == 'S') || 
               (c == 'P' && S[i] == 'R') || 
               (c == 'S' && S[i] == 'P')) {
                use = c;
                total++;
                won = true;
                break;
            }
        }
        
        // Update next possible moves
        vector<char> new_next;
        for(auto c : hand) {
            if(c != use) {
                new_next.push_back(c);
            }
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
    
    // Two possible scenarios: play normally or skip first move
    int res1 = solve(S, hand);
    
    // For the second scenario, skip first move
    if (N == 0) {
        cout << 0;
        return 0;
    }
    
    // Find valid moves after skipping first move
    vector<char> next;
    for(auto c : hand) {
        if(c != S[0]) {
            next.push_back(c);
        }
    }
    
    string sub = S.substr(1);
    int res2 = solve(sub, next);
    
    cout << max(res1, res2);
    return 0;
}