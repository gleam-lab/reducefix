#include <bits/stdc++.h>
using namespace std;

int calculateMaxScore(const string& S) {
    int N = S.size();
    if (N == 0) return 0;
    
    int maxScore = 0;
    // Try all possible initial moves
    for (char initial : {'R', 'P', 'S'}) {
        int score = 0;
        char prev = initial;
        
        // First move
        if ((prev == 'R' && S[0] == 'S') ||
            (prev == 'P' && S[0] == 'R') ||
            (prev == 'S' && S[0] == 'P')) {
            score++;
        }
        
        // Subsequent moves
        for (int i = 1; i < N; i++) {
            char current;
            // Try the move that would beat the current opponent's move
            if (S[i] == 'R') current = 'P';
            else if (S[i] == 'P') current = 'S';
            else current = 'R';
            
            // If the move would be same as previous, try the alternative
            if (current == prev) {
                if (current == 'R') current = (S[i] == 'S') ? 'R' : 'P';
                else if (current == 'P') current = (S[i] == 'R') ? 'P' : 'S';
                else current = (S[i] == 'P') ? 'S' : 'R';
            }
            
            // Calculate score
            if ((current == 'R' && S[i] == 'S') ||
                (current == 'P' && S[i] == 'R') ||
                (current == 'S' && S[i] == 'P')) {
                score++;
            }
            prev = current;
        }
        maxScore = max(maxScore, score);
    }
    return maxScore;
}

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    cout << calculateMaxScore(S) << endl;
    return 0;
}