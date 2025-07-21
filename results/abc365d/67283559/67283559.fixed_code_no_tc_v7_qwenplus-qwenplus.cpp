#include <bits/stdc++.h>
using namespace std;

int playGame(const string& S, const vector<char>& hand, int N, bool firstMoveRandom) {
    vector<char> next = hand;
    int total = 0;
    
    for (int i = 0; i < N; ++i) {
        int score = 0;
        char use;
        
        // Try each possible move
        for (char n : next) {
            if ((n == 'R' && S[i] == 'S') || 
                (n == 'P' && S[i] == 'R') || 
                (n == 'S' && S[i] == 'P')) {
                score = 1;
                use = n;
                break;
            }
        }

        if (score == 0) {
            // No winning move available, choose any
            use = next[0];
        }

        total += score;
        
        // Update available moves for next round
        vector<char> newNext;
        for (char d : hand) {
            if (d != use) newNext.push_back(d);
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
    
    // First scenario: we can choose any starting move
    int result1 = playGame(S, hand, N, false);
    
    // Second scenario: our first move must beat the first character
    int result2 = 0;
    vector<char> next;
    
    // Determine valid responses to first character
    if (S[0] == 'R') next = {'P'};   // Only paper beats rock
    else if (S[0] == 'P') next = {'S'}; // Only scissors beats paper
    else if (S[0] == 'S') next = {'R'}; // Only rock beats scissors
    
    if (!next.empty()) {
        int score = 1;
        char use = next[0];
        result2 = score + playGame(S.substr(1), hand, N-1, false);
    }
    
    cout << max(result1, result2);
    return 0;
}